#include "Map.h"
#include "core/file.h"
#include "res/SingleResAnim.h"
#include "Material.h"
#include "Utils.h"

Map::Map(const std::string & tmx, const std::string & texture)
{
	oxygine::file::buffer fb;
	oxygine::file::read(tmx, fb);
	pugi::xml_document doc;
	doc.load_buffer(fb.getData(), fb.getSize());
	pugi::xml_node map = doc.document_element();
	width = map.attribute("width").as_int();
	height = map.attribute("height").as_int();
	tileWidth = map.attribute("tilewidth").as_int();
	tileHeight = map.attribute("tileheight").as_int();
	pugi::xml_node layerNode = map.child("layer");
	while (!strcmp(layerNode.name(), "layer"))
	{
		pugi::xml_node data = layerNode.child("data");
		pugi::xml_node tile = data.first_child();
		std::vector<unsigned int> layer;
		int nr_layers = 0;
		while (nr_layers < width * height)
		{
			for (int i = 0; i < tile.attribute("nr-repeats").as_uint() && nr_layers < width * height; ++i)
			{
				layer.push_back(tile.attribute("gid").as_uint());
				++nr_layers;
			}
			if (!tile.attribute("nr-repeats").as_uint())
				++nr_layers;
			tile = tile.next_sibling();
		}
		layers.push_back(layer);
		layerNode = layerNode.next_sibling();
	}
	oxygine::Image src;
	oxygine::file::read(texture, fb);
	src.init(fb, true);
	createTileSetTexture(src);
}

void Map::drawLayer(int startX, int startY, int endX, int endY, const std::vector<unsigned int>& layer)
{
	const std::vector<unsigned int>& tiles = layer;
	oxygine::Color color(oxygine::Color::White);
	oxygine::STDRenderer* renderer = oxygine::STDRenderer::instance;
	float tw = 1.0f / nt->getWidth();
	float th = 1.0f / nt->getHeight();
	for (int y = startY; y < endY; ++y)
	{
		for (int x = startX; x < endX; ++x)
		{
			unsigned int tile = tiles[y * width + x];
			if (!tile)
				continue;
			tile = tile - 1;
			bool flipped_horizontally = (tile & Utils::FLIPPED_HORIZONTALLY_FLAG) ? true : false;
			bool flipped_vertically = (tile & Utils::FLIPPED_VERTICALLY_FLAG) ? true : false;
			bool flipped_diagonally = (tile & Utils::FLIPPED_DIAGONALLY_FLAG) ? true : false;
			tile &= ~(Utils::FLIPPED_HORIZONTALLY_FLAG |
				Utils::FLIPPED_VERTICALLY_FLAG |
				Utils::FLIPPED_DIAGONALLY_FLAG);
			int col = tile % cols;
			int row = tile / cols;
			oxygine::Rect src(col * (tileWidth + 2) + 1, row * (tileHeight + 2) + 1, tileWidth, tileHeight);
			if (flipped_horizontally)
			{
				src.pos.x += tileWidth;
				src.size.x *= -1;
			}
			if (flipped_vertically)
			{
				src.pos.y += tileHeight;
				src.size.y *= -1;
			}
			oxygine::RectF srcUV = src.cast<oxygine::RectF>();
			srcUV.pos.x *= tw;
			srcUV.pos.y *= th;
			srcUV.size.x *= tw;
			srcUV.size.y *= th;
			oxygine::Rect dest(x * tileWidth, y * tileHeight, tileWidth, tileHeight);
			oxygine::RectF destF = dest.cast<oxygine::RectF>();
			renderer->draw(color, srcUV, destF);
		}
	}
}

void Map::createTileSetTexture(oxygine::Image & src)
{
	cols = src.getWidth() / tileWidth;
	rows = src.getHeight() / tileHeight;
	oxygine::Image dest;
	dest.init(cols * (tileWidth + 2), rows * (tileHeight * 2), oxygine::TF_R8G8B8A8);
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
		{
			oxygine::Rect srcRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight);
			oxygine::Rect destRect = srcRect;
			destRect.pos.x += 2 * x + 1;
			destRect.pos.y += 2 * y + 1;
			oxygine::ImageData srcIm = src.lock(srcRect);
			oxygine::ImageData destIm = dest.lock(destRect);
			oxygine::operations::blit(srcIm, destIm);
			destRect.expand(oxygine::Point(1, 1), oxygine::Point(1, 1));
			oxygine::operations::blit(
				dest.lock(destRect.pos.x + 1, destRect.pos.y + 1, tileWidth, 1),
				dest.lock(destRect.pos.x + 1, destRect.pos.y, tileWidth, 1));
			oxygine::operations::blit(
				dest.lock(destRect.pos.x + 1, destRect.pos.y + tileHeight, tileWidth, 1),
				dest.lock(destRect.pos.x + 1, destRect.pos.y + tileHeight + 1, tileWidth, 1));
			oxygine::operations::blit(
				dest.lock(destRect.pos.x + 1, destRect.pos.y, 1, tileHeight + 2),
				dest.lock(destRect.pos.x, destRect.pos.y, 1, tileHeight + 2));
			oxygine::operations::blit(
				dest.lock(destRect.pos.x + tileWidth, destRect.pos.y, 1, tileHeight + 2),
				dest.lock(destRect.pos.x + tileWidth + 1, destRect.pos.y, 1, tileHeight + 2));
		}
	}
	nt = oxygine::IVideoDriver::instance->createTexture();
	nt->init(dest.lock());
	nt->setClamp2Edge(true);
	nt->setLinearFilter(false);
}

void Map::doRender(const oxygine::RenderState & rs)
{
	oxygine::Material::setCurrent(rs.material);

	oxygine::STDRenderer* renderer = oxygine::STDRenderer::instance;
	renderer->setTexture(nt);
	renderer->setTransform(rs.transform);
	renderer->setBlendMode(oxygine::blend_premultiplied_alpha);


	oxygine::Transform world = rs.transform;
	world.invert();

	//find top left local position of TiledActor visible on display
	oxygine::Vector2 topLeft = world.transform(oxygine::Vector2(0, 0));

	//find bottom right local position of TiledActor visible on display
	oxygine::Vector2 bottomRight = world.transform(oxygine::getStage()->getSize());

	//we don't want to draw tiles outside of visible area
	int startX = std::max(0, int(topLeft.x / tileWidth));
	int startY = std::max(0, int(topLeft.y / tileHeight));
	int endX = std::min(width, int(bottomRight.x / tileWidth) + 1);
	int endY = std::min(height, int(bottomRight.y / tileHeight) + 1);

	for (std::list< std::vector<unsigned int> >::const_iterator i = layers.begin(); i != layers.end(); ++i)
		drawLayer(startX, startY, endX, endY, *i);
}
