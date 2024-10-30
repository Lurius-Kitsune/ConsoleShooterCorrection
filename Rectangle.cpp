#include "Rectangle.h"

Rectangle::Rectangle(const float _length, const float _width, const string& _color)
	: Shape(_color)
{
	length = _length;
	width = _width;
}

float Rectangle::CalcArea()const
{
	return length * width;
}

float Rectangle::CalcPerimeter()const
{
	return (length+width) * 2;
}
