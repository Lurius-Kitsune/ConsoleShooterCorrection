#pragma once
#include "Macro.h"

class Shape
{
protected:
	string color;
public:
	Shape();

	Shape(const string& _color);

protected:
	virtual float CalcArea()const  = 0;
	virtual float CalcPerimeter() const = 0;

public:
	void Introduce(const string& _name);
};

