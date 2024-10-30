#include "Square.h"

Square::Square(const float _side, const string& _color) : Shape(_color)
{
    side = _side;
}

float Square::CalcArea()const
{
    return side*side;
}

float Square::CalcPerimeter()const
{
    return side*4;
}

void Square::Bob() const
{
    DISPLAY("JE SUIS MAGUERITE", true)
}
