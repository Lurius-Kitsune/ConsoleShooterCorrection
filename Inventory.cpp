#include "Inventory.h"

Inventory::Inventory()
{
	consumablesCount = 0;
	consumables = new Consumable * [consumablesCount];
}

Inventory::~Inventory()
{
	for (u_int _i = 0; _i < consumablesCount; _i++)
	{
		delete consumables[_i];
	}

	delete[] consumables;
}

void Inventory::AddConsumable(Consumable* _consumable)
{
	Consumable** _tempWeapons = new Consumable * [consumablesCount + 1];
	for (u_int _i = 0; _i < consumablesCount; _i++)
	{
		_tempWeapons[_i] = consumables[_i];
	}

	_tempWeapons[consumablesCount] = _consumable;
	delete consumables;
	consumables = _tempWeapons;
	consumablesCount++;
}

void Inventory::RemoveConsumable(const ConsumableType* _type)
{
	Consumable** _tempConsumables = new Consumable * [--consumablesCount];
	bool _hasSkip = false;
	for (u_int _i = 0; _i < consumablesCount; _i++)
	{
		if (!_hasSkip && _type == &consumables[_i]->type)
		{
			_hasSkip = true;
			delete consumables[_i];
			continue;
		}
		_tempConsumables[_i] = consumables[_i + _hasSkip];
	}
	delete consumables;
	consumables = _tempConsumables;
}
