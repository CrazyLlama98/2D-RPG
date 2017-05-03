#include "Entity.h"
#include "Utils.h"

Entity::Entity(const oxygine::ResAnim *_res, b2World *_world, const oxygine::Vector2 & _pos, 
	const b2BodyType _def, const float _scale)
{
	setResAnim(_res);

	setAnchor(oxygine::Vector2(0.5f, 0.5f));
	setTouchChildrenEnabled(false);
	b2BodyDef bodyDef;
	bodyDef.type = _def;
	bodyDef.position = Utils::convert(_pos);
	b2Body* body = _world->CreateBody(&bodyDef);
	setUserData(body);
	setScale(_scale);
	b2PolygonShape shape;
	shape.SetAsBox(getWidth() / Utils::scale / 2 * _scale, getWidth() / Utils::scale / 2 * _scale);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
	body->SetUserData(this);
}

Entity::~Entity()
{
	detach();
}
