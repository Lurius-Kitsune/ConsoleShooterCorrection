#pragma once
#include "WeaponWheel.h"
#include "Inventory.h"

class Entity
{
	string name;
	int maxLife;
	int life;
	Weapon* currentWeapon;
	WeaponWheel* wheel;
	Inventory* inventory;

public:
	WeaponWheel* GetWheel()const
	{
		return wheel;
	}

	Inventory* GetInventory()const
	{
		return inventory;
	}

public:
	Entity();
	Entity(const string& _name, const int _life,
		WeaponWheel* _wheel);
	Entity(const string& _name, const int _life, 
		WeaponWheel* _wheel, Inventory* _inventory);

	~Entity();


public:
	//virtual void OpenInventory() = 0;
	//virtual void ChangeWeapon(_weapo)
	virtual void TakeDamage(const int _damage);
	virtual string ToString()const;

private:
	string RenderLife()const;
};

