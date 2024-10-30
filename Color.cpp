#include "Color.h"

string RainbowString(string _word, const u_int _wordSize)
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

	const u_int _rainbowSize = size(_rainbowTable);
	string _newWord = "";
	for (u_int _i = 0; _i < _wordSize; _i++)
	{
		_newWord += _rainbowTable[RandomInt(_rainbowSize, 0)] + _word[_i];
	}

	return _newWord + RESET;
}
