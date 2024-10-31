#include "Inventory.h"

Inventory::Inventory()
{
	purchasablesCount = 2;
	allData = new InventoryData[2]
	{
		InventoryData("Consomable"),
		InventoryData("Munition"),
	};
	purchasables = new PurchasableItem * [0];
}

Inventory::~Inventory()
{
	const u_int& _purchasablesSize = GetPurchasablesSize();
	for (u_int _i = 0; _i < _purchasablesSize; _i++)
	{
		delete purchasables[_i];
	}
	delete[] purchasables;

	delete[] allData;
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
		_menuIndex = OpenMenu(_inventoryCategoriesNames, _inventoryCategoriesCount, "Quel magasin accéder ?");
		CLEAR_SCREEN;
		if (_menuIndex >= 0 && _menuIndex < purchasablesCount)
		{
			OpenType(_menuIndex);
		}
		else
		{
			break;
		}
	} while (true);

}

void Inventory::OpenType(const u_int& _categoryIndex)
{
	const u_int& _purchasablesSize = InventorySize;
	const u_int& _indexToLook = GetPurchasablesSize(_categoryIndex);
	if(_indexToLook > 0)
	{
		string* _namesOfType = GetNamesOfType(_indexToLook);
		const u_int& _consumablesIndex = OpenMenu(_namesOfType, _indexToLook, "Quelle item souhaitez-vous acheter ?");
		delete[] _namesOfType;

		Consumable* _consumable = dynamic_cast<Consumable*>(purchasables[_indexToLook + _consumablesIndex]);
		do
		{
			if (_consumablesIndex < _indexToLook)
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
	else
	{
		DISPLAY(RED "[INFO] Tu ne possède aucun consomable" RESET, true);
	}
}

string* Inventory::GetNamesOfType(const u_int& _indexToLook) const
{
	string* _newArray = new string[_indexToLook];
	for (u_int _i = 0; _i < _indexToLook; _i++)
	{
		_newArray[_i] = purchasables[_i + _indexToLook]->GetTypeName();
	}
	return _newArray;
}

void Inventory::Add(const u_int& _categoryIndex, PurchasableItem* _purchase)
{
	const u_int& _inventorySize = InventorySize;
	PurchasableItem** _tempPurchasable = new PurchasableItem *[_inventorySize + 1];
	const u_int& _indexToAdd = GetPurchasablesSize(_categoryIndex);
	bool _hasSet = false;

	for (u_int _i = 0; _i < _inventorySize; _i++)
	{
		if (_i == _indexToAdd)
		{
			_tempPurchasable[_i] = _purchase;
			_hasSet = true;
		}
		_tempPurchasable[_i + _hasSet] = purchasables[_i];
	}

	delete purchasables;
	purchasables = _tempPurchasable;
	allData[_categoryIndex].count++;
}

bool Inventory::Remove(const PurchasableType& _purchaseType, const AllPurchasableType& _type)
{
	const u_int& _inventorySize = InventorySize;
	const u_int& _indexToRemove = GetIndexByType(_purchaseType, _type);

	if (_indexToRemove == _inventorySize) return false;

	// Todo Check index

	PurchasableItem** _tempPurchasable = new PurchasableItem * [_inventorySize - 1];
	bool _hasSkip = false;
	PurchasableItem* _purchase;
	for (u_int _i = 0; _i < _inventorySize; _i++)
	{
		if (!_hasSkip && _i == _indexToRemove)
		{
			_hasSkip = true;
			_purchase = purchasables[_i];
			continue;
		}
		_tempPurchasable[_i] = purchasables[_i + _hasSkip];
	}
	delete purchasables;
	purchasables = _tempPurchasable;
}

u_int Inventory::GetIndexByType(const PurchasableType& _purchaseType, const AllPurchasableType& _type) const
{
	return u_int();
}
