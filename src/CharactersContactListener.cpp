#include "CharactersContactListener.h"
#include "Utils.h"
#include <iostream>

void CharactersContactListener::BeginContact(b2Contact * contact)
{
	Character* firstChar = static_cast<Character*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Character* secondChar = static_cast<Character*>(contact->GetFixtureB()->GetBody()->GetUserData());
	firstChar->removeTweens();
	oxygine::Vector2 pos(firstChar->getPosition().x - 5, firstChar->getPosition().y - 5);
	firstChar->addTween(oxygine::createTween(oxygine::Actor::TweenPosition(pos), 500));
}
