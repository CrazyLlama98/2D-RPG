#include "Entity.h"
#include "Utils.h"

Entity::Entity(b2World *_world, b2BodyType _bodyDefinition, const oxygine::Vector2 & _pos, const float _scale)
{
	setAnchor(oxygine::Vector2(0.5f, 0.5f));
	setTouchChildrenEnabled(false);
	b2BodyDef bodyDef;
	bodyDef.type = _bodyDefinition;
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
