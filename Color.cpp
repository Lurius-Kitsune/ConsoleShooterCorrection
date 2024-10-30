#include "Color.h"

string RainbowString(const string& _word)
{
	const string _rainbowTable[] =
	{
		WHITE,
		DARK_RED,
		RED ,
		DARK_ORANGE ,
		ORANGE,
		DARK_YELLOW,
		YELLOW,
		LIME,
		GREEN,
		BLUE,
		LIGHT_BLUE,
		CYAN,
		PINK,
		MAGENTA,
		PURPLE,
		BROWN
	};

	const u_int _rainbowSize = size(_rainbowTable)-1;
	string _newWord = "";
	for (u_int _i = 0; _i < _word.length(); _i++)
	{
		_newWord += _rainbowTable[RandomInt(_rainbowSize, 0)] + _word[_i];
	}

	return _newWord + RESET;
}

void DisplayRainbow(const string& _text)
{
	while (!_kbhit())
	{
		CLEAR_SCREEN;
		DISPLAY(RainbowString(_text), true);
		const auto _start = high_resolution_clock::now();
		sleep_for(200ms);
		const auto _end = high_resolution_clock::now();
		const duration<double, milli> _elapsed = _end - _start;
	}
}
