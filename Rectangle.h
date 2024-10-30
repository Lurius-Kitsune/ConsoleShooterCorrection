#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
	float length;
	float width;

public:
	Rectangle(const float _length, const float _width, const string& _color);
public:
	virtual float CalcArea()const;
	virtual float CalcPerimeter()const;
};

