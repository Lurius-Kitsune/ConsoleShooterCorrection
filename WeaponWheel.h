#pragma once
#include "Weapon.h"

class WeaponWheel
{
	Weapon** allWeapons;
	u_int weaponsCount;

public:
	WeaponWheel();
	~WeaponWheel();

public:
	void Display() const;
	bool AddWeapon(Weapon* _weapon);
	bool RemoveWeapon(Weapon* _weapon);
	bool RemoveWeaponByIndex(const u_int& _index);
	bool ConstainsWeapon(Weapon* _weapon)const;
	bool IsValidIndex(const u_int& _index) const;
	Weapon* GetWeaponByIndex(const u_int& _index)const;
	Weapon* GetWeaponByName(const string& _name) const;
};

