#pragma once
#include "Weapon.h"
class Soldier
{
	string name;
	float life;
	Weapon* currentWeapon;
	Weapon** weapons;
	u_int weaponsSize;


public:

	string GetName() const
	{
		return name;
	}

	Weapon* GetCurrentWeapon() const
	{
		return currentWeapon;
	}

	u_int GetWeaponsSize() const
	{
		return weaponsSize;
	}

	string* GetWeaponsList() const
	{
		string* _weaponsList = new string[weaponsSize];
		for (u_int _i = 0; _i < weaponsSize; _i++)
		{
			_weaponsList[_i] = weapons[_i]->GetName();
		}
		return _weaponsList;
	}

	Soldier() = default;

	Soldier(const string& _name, const int _life, Weapon* _currentWeapon);
	Soldier(const string& _name, const int _life, Weapon* _currentWeapon, Weapon** _weapons, const u_int& _weaponsSize);
	~Soldier();
public:
	bool ShootWithWeapon(Soldier*& _receiver);
	void Reload();
	bool ReceiveDamage(Soldier* _attacker, const float _damage);
	void AddWeapon(Weapon* _weapon);
	void SetCurrentWeapon(const u_int& _weaponIndex);
	Weapon* RunAway();
	Weapon* DropWeapon();

	string ToString()const;
private:
	void Death(Soldier*& _attacker);
	bool IsValidWeaponIndex(const u_int _weaponIndex);
};

