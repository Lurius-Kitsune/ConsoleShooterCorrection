#include "WeaponWheel.h"

WeaponWheel::WeaponWheel()
{
}

WeaponWheel::~WeaponWheel()
{
	for (u_int _i = 0; _i < weaponsCount; _i++)
	{
		delete allWeapons[_i];
	}
	
	delete[] allWeapons;
}

void WeaponWheel::Display() const
{
	for (u_int _i = 0; _i < weaponsCount; _i++)
	{
		DISPLAY(allWeapons[_i]->ToString(), true);
	}
}

void WeaponWheel::AddWeapon(Weapon* _weapon)
{
}

void WeaponWheel::RemoveWeapon(Weapon* _weapon)
{
}

void WeaponWheel::RemoveWeaponByIndex(const u_int& _index)
{
}

bool WeaponWheel::ConstainsWeapon(Weapon* _weapon) const
{
	return false;
}

bool WeaponWheel::IsValidIndex(const u_int& _index) const
{
	return false;
}

Weapon* WeaponWheel::GetWeaponByIndex(const u_int& _index) const
{
	return nullptr;
}

Weapon* WeaponWheel::GetWeaponByName(const string& _name) const
{
	return nullptr;
}
