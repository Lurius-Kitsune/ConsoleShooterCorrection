#include "Entity.h"

Entity::Entity()
{
	name = "???";
	maxLife = 20;
	life = maxLife;
	currentWeapon = nullptr;
	wheel = new WeaponWheel();
	inventory = new Inventory();
}

Entity::Entity(const string& _name, const int _life, WeaponWheel* _wheel)
{
	name = _name;
	maxLife = _life;
	life = maxLife;
	wheel = _wheel;
	currentWeapon = wheel->GetWeaponByIndex(0);
	inventory = new Inventory();
}

Entity::Entity(const string& _name, const int _life, WeaponWheel* _wheel, Inventory* _inventory)
{
	name = _name;
	maxLife = _life;
	life = maxLife;
	wheel = _wheel;
	currentWeapon = wheel->GetWeaponByIndex(0);
	inventory = _inventory;
}


Entity::~Entity()
{
	delete wheel;
	delete inventory;
}

void Entity::TakeDamage(const int _damage)
{
	life -= _damage;
}

string Entity::ToString()const
{
	return "[" + name + "] :\n" +
		"  " + RenderLife() + RESET + "\n" +
		"  [Weapon] : " + (currentWeapon ? currentWeapon->ToString() : "None");
}

string Entity::RenderLife()const
{
	int _percentLife = life * 100 / maxLife;
	string _lifeColor = _percentLife <= 75 ?
		_percentLife <= 50 ?
		_percentLife <= 25 ?
		_percentLife <= 15 ? RED : ORANGE : YELLOW : GREEN : BLUE;
	string _lifeDisplay = _lifeColor;
	for (int _i = 0; _i < life; _i++)
	{
		_lifeDisplay += "#";
	}
	return "[HP " + to_string(life) + "/" + to_string(maxLife) + "] " + _lifeDisplay + RESET;
}
