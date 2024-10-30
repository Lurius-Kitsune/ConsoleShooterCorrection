#pragma once
#define _USE_MATH_DEFINES // for C++
#include "Shape.h"
#include <cmath>

class Circle : public Shape
{
	float radius;

public:
	Circle(const float _radius, const string& _color);
public:
	virtual float CalcArea()const;
	virtual float CalcPerimeter()const;
};

