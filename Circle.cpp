#include "Circle.h"

Circle::Circle(const float _radius, const string& _color) : Shape(_color)
{
	radius = _radius;
}

float Circle::CalcArea()const
{
	return M_PI *(radius*radius);
}

float Circle::CalcPerimeter()const
{
	return (radius*2)* M_PI;
}
