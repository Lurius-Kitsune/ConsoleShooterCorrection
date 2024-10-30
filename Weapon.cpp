#include "Weapon.h"

Weapon::Weapon(const string& _name, const string& _description, const int _buyingPrice, 
	const string& _skin, const float _accuracy)
{
	name = _name;
	description = _description;
	buyingPrice = _buyingPrice;
	skin = _skin;
	accuracy = _accuracy;
}

void Weapon::Drop()
{
	// TODO
	DISPLAY("Arme laché!", true);
}
