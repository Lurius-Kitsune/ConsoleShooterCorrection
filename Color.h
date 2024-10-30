#pragma once
#include "Macro.h"
struct Color
{
	union Value
	{
		struct
		{
			int red;
			int green;
			int blue;
			int alpha;
		};

		string* hex = nullptr;

		Value()
		{
			red = 255;
			green = 255;
			blue = 255;
			alpha = 255;
			hex = nullptr;
		}

		Value(const int _red, const int _green, const int _blue, const int _alpha = 255)
		{
			red = _red > 255 ? 255 : _red;
			green = _green > 255 ? 255 : _green;
			blue = _blue > 255 ? 255 : _blue;
			alpha = _alpha > 255 ? 255 : _alpha;
		}

		Value(const string& _hexa)
		{
			hex = new string(_hexa);
		}

		~Value() {};

		void operator = (const Value& _color)
		{
			red = _color.red;
			green = _color.green;
			blue = _color.blue;
			alpha = _color.alpha;
		}
	} rgb, hexa;

	Color(const int _red, const int _green, const int _blue, const int _alpha = 255)
	{
		rgb = Value(_red, _green, _blue, _alpha);
	}

	Color(const string& _hex)
	{
		hexa = Value(_hex);
	}

	string ToString() const
	{
		if (hexa.hex) return *hexa.hex;
		return "{ " + to_string(rgb.red) + " "
			+ to_string(rgb.green) + " "
			+ to_string(rgb.blue) + " "
			+ to_string(rgb.alpha) + " }";
	}
};
