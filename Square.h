#pragma once
#include "Shape.h"

class Square : public Shape
{
	float side;

public :
	Square(const float _side, const string& _color);
public :
	virtual float CalcArea()const;
	virtual float CalcPerimeter()const;
	void Bob() const;
};

