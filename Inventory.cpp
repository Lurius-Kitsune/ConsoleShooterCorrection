#include "Inventory.h"

Inventory::Inventory()
{
	consumablesCount = 0;
	consumables = new Consumable * [consumablesCount];
	bulletsCount = 0;
	bullets = new Bullet * [bulletsCount];
}

Inventory::~Inventory()
{
	for (u_int _i = 0; _i < consumablesCount; _i++)
	{
		delete consumables[_i];
	}

	delete[] consumables;

	for (u_int _i = 0; _i < bulletsCount; _i++)
	{
		delete bullets[_i];
	}

	delete[] bullets;
}

void Inventory::Open()
{
	const string _inventoryCategoriesNames[] =
	{
		"Consomable",
		"Bullet"
	};

	const u_int& _inventoryCategoriesCount = size(_inventoryCategoriesNames);
	int _menuIndex;
	do
	{
		CLEAR_SCREEN;
		_menuIndex = OpenMenu(_inventoryCategoriesNames, _inventoryCategoriesCount, "Quel magasin accéder ?");
		if (_menuIndex == 0)
		{
			OpenConsumable();
		}
		else if (_menuIndex == 1)
		{
			OpenBullet();
		}
		else
		{
			break;
		}
	} while (true);

}

void Inventory::OpenConsumable()
{
	string* _consumablesName = GetConsumablesName();
	const u_int& _consumablesIndex = OpenMenu(_consumablesName, bulletsCount, "Quelle item souhaitez-vous acheter ?");
	delete[] _consumablesName;

	Consumable* _consumable = consumables[_consumablesIndex];
	do
	{
		if (_consumablesIndex < consumablesCount)
		{
			DISPLAY("Using consumable: " + _consumable->GetTypeName(), true);
			RemoveConsumableByType(&_consumable->type);
		}
		else
		{
			break;
		}
	} while (true);
}

string* Inventory::GetConsumablesName() const
{
	string* _newArray = new string[consumablesCount];
	for (u_int _i = 0; _i < consumablesCount; _i++)
	{
		_newArray[_i] = consumables[_i]->GetTypeName();
	}
	return _newArray;
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

void Inventory::RemoveConsumableByType(const ConsumableType* _type)
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

void Inventory::OpenBullet()
{
	string* _bulletsName = GetBulletsName();
	const u_int& _bulletIndex = OpenMenu(_bulletsName, bulletsCount, "Quelle item souhaitez-vous acheter ?");
	delete[] _bulletsName;

	Bullet* _bullet = bullets[_bulletIndex];
	do
	{
		if (_bulletIndex < bulletsCount)
		{
			DISPLAY("Using bullet: " + _bullet->GetTypeName(), true);
			RemoveBulletByType(_bullet->type);
		}
		else
		{
			break;
		}
	} while (true);
}

string* Inventory::GetBulletsName() const
{
	string* _newArray = new string[bulletsCount];

	for (u_int _index = 0; _index < bulletsCount; _index++)
	{
		_newArray[_index] = bullets[_index]->GetTypeName();
	}

	return _newArray;
}

void Inventory::AddBullet(Bullet* _bullet)
{
	Bullet** _newArray = new Bullet * [bulletsCount + 1];

	for (u_int _index = 0; _index < bulletsCount; _index++)
	{
		_newArray[_index] = bullets[_index];
	}

	_newArray[bulletsCount] = _bullet;
	delete[] bullets;
	bullets = _newArray;
	bulletsCount++;
}

void Inventory::RemoveBulletByType(const BulletType& _type)
{
	Bullet** _newArray = new Bullet * [--bulletsCount];
	bool _hasSkip = false;
	Bullet* _bullet = nullptr;

	for (u_int _index = 0; _index < bulletsCount; _index++)
	{
		if (!_hasSkip && _type == bullets[_index]->type)
		{
			_hasSkip = true;
			_bullet = bullets[_index];
		}
		_newArray[_index] = bullets[_index + _hasSkip];
	}

	delete _bullet;
	delete[] bullets;
	bullets = _newArray;
}
