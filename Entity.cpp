#include "Entity.h"

Entity::Entity()
{
	wheel = new WeaponWheel();
	inventory = new Inventory();
}

Entity::~Entity()
{
	delete wheel;
	delete inventory;
}

string Entity::ToString()
{
	return "[" + name + "] \n" +
		GREEN + "\t[HP] " + RenderLife() + RESET + "\n" +
		currentWeapon->ToString();
}

string Entity::RenderLife()
{
	string _life = "";
	for (int _i = 0; _i < life; _i++)
	{
		_life += "#";
	}
	return GREEN + _life + RESET;
}
