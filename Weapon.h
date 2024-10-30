#pragma once
#include "Macro.h"

class Weapon
{
	string name;
	u_int maxAmmo;
	u_int currentAmmo;
	u_int bulletPerShot;
	u_int damagePerShot;
	u_int magazine;
	u_int maxMagazine;

public:
	string GetName()const
	{
		return name;
	}

	u_int GetMaxAmmo() const
	{
		return maxAmmo;
	}

	u_int GetCurrentAmmo() const
	{
		return currentAmmo;
	}

	Weapon();
	Weapon(const string& _name, const u_int& _maxAmmo, const u_int& _bulletPerShot,
		const u_int& _damagePerShot, const u_int& _maxMagazine);

	string ToString();
public:
	virtual int Shoot();
	virtual void Reload();
	virtual void AddOnMagazine(const u_int& _nbAmmoFound);
};

