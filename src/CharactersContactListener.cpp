#include "CharactersContactListener.h"
#include "Utils.h"

void CharactersContactListener::BeginContact(b2Contact * contact)
{
	Character* firstChar = static_cast<Character*>(contact->GetFixtureA()->GetBody()->GetUserData());
	firstChar->removeTweens();
	oxygine::Vector2 pos(Utils::convert(contact->GetFixtureA()->GetBody()->GetPosition()).x - 5, Utils::convert(contact->GetFixtureA()->GetBody()->GetPosition()).y - 5);
	firstChar->addTween(oxygine::createTween(oxygine::Actor::TweenPosition(pos), 500));
}
