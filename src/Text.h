#pragma once
#include "oxygine-framework.h"

class string;
DECLARE_SMART(Text, spText);

class Text : public oxygine::TextField
{
public:
	Text(std::string &_text, oxygine::Color _color, oxygine::Vector2 _pos, bool _rand = true, int _duration = 1000, bool _floating = true);
	void SetText(std::string &_text) { setText(_text); }
};