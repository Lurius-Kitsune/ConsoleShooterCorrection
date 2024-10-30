#include "Shape.h"

Shape::Shape()
{
	color = WHITE;
}

Shape::Shape(const string& _color)
{
	color = _color;
}

void Shape::Introduce(const string& _name)
{
	DISPLAY(color + "["+ _name +"]", true);
	DISPLAY("A un air de " + to_string(CalcArea()) + " cm²", true);
	DISPLAY("A un perimètre de " + to_string(CalcPerimeter()) + " cm", true);
	DISPLAY(RESET, true);
}
