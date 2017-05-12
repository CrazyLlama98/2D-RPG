#include "Text.h"
#include "res.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>

Text::Text(std::string &_text, oxygine::Color _color, oxygine::Vector2 _pos, bool _rand, int _duration, bool _floating)
{
	oxygine::TextStyle style;

	style.font = res::resources.getResFont("main");
	style.vAlign = oxygine::TextStyle::VALIGN_MIDDLE;
	style.color = _color;

	setSize(oxygine::Vector2(50, 50));
	srand(time(0));
	oxygine::Vector2 random;
	if (_rand)
		random.x = rand() % 50 + _pos.x;
	else random.x = _pos.x;
	random.y = _pos.y;
	setPosition(random);
	setStyle(style);
	setText(_text);

	if (_floating)
		addTween(TweenPosition(random - oxygine::Vector2(0, 50)), _duration)->detachWhenDone();
	else if (_duration) addTween(oxygine::TweenDummy(), _duration)->detachWhenDone();
}