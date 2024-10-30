#include "Weapon.h"

Weapon::Weapon(const string& _name, const string& _description, const string& _skin, 
	const int _buyingPrice, const float _accuracy)
{
	name = _name;
	description = _description;
	purchasePrice = _buyingPrice;
	skin = _skin;
	accuracy = _accuracy;
}

string Weapon::ToString()
{
	return "[Weapon] :" + (this ? name +
		"\n\t->" + description + 
		"\n\t->" + to_string(purchasePrice) + "€" +
		+"\n\t->" + skin +
		+"\n\t->" + to_string(accuracy)
		: "NONE");
}

void Weapon::Drop()
{
	// TODO
	DISPLAY("Arme laché!", true);
}

bool Weapon::operator==(const Weapon& _other)
{
	return name == _other.name;
}
