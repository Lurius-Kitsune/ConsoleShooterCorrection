#include "Animal.h"

Animal::Animal()
{
	name = new string("Margueritte");
	pawsCount = 4;
	life = 100.0f;
}

Animal::Animal(const string& _name, const int _pawsCount, const float _life)
{
	name = new string(_name);
	pawsCount = _pawsCount;
	life = _life;
}

Animal::~Animal()
{
	DISPLAY("Destructeur Animal", true);
	delete name;
}


void Animal::Introduce()
{
	DISPLAY("Bonjour je suis " + *name + " j'ai " + to_string(pawsCount) + " patte et " + to_string(life) + " PV", true);
}

