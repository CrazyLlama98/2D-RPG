#pragma once
#include "oxygine-framework.h"

DECLARE_SMART(Map, spMap);
class Map : public oxygine::Sprite 
{
public:
	Map(const std::string& tmx, const std::string& texture);

	int GetWidth() const { return width; };
	void SetWidth(const int _width) { width = _width; };

	int GetHeight() const { return height; };
	void SetHeight(const int _height) { height = _height; };

	int GetCols() const { return cols; };
	void SetCols(const int _cols) { cols = _cols; };

	int GetRows() const { return rows; };
	void SetRows(const int _rows) { rows = _rows; };

	void drawLayer(int startX, int startY, int endX, int endY, const std::vector<unsigned int>& layer);
	void createTileSetTexture(oxygine::Image& src);
	void doRender(const oxygine::RenderState& rs);

private:
	std::list< std::vector<unsigned int> > layers;
	int width, height, tileWidth, tileHeight, cols, rows;
	oxygine::spNativeTexture nt;
};