#include "Inventory.h"

Inventory::Inventory()
{
	allData = new InventoryData[2]
	{
		InventoryData("Consomable"),
		InventoryData("Munition"),
	};
	purchasables = new Purchasable * [0];
}

Inventory::~Inventory()
{
	const u_int& _purchasablesSize = InventorySize;
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
		"Munition",
		"Consomable"
	};

	const u_int& _inventoryCategoriesCount = size(_inventoryCategoriesNames);
	int _menuIndex;
	do
	{
		_menuIndex = OpenMenu(_inventoryCategoriesNames, _inventoryCategoriesCount, "Quel magasin accéder ?");
		CLEAR_SCREEN;
		if (_menuIndex >= 0 && _menuIndex < PT_COUNT)
		{
			OpenType(PurchasableType(_menuIndex));
		}
		else
		{
			break;
		}
	} while (true);

}

void Inventory::OpenType(const PurchasableType& _category)
{
	const u_int& _purchasablesSize = InventorySize;
	const u_int& _indexToLook = GetPurchasablesSize(_category);
	if(_indexToLook > 0)
	{
		string* _namesOfType = GetNamesOfType(_indexToLook);
		const u_int& _consumablesIndex = OpenMenu(_namesOfType, _indexToLook, "Quelle item souhaitez-vous acheter ?");
		delete[] _namesOfType;

		// Todo Upgrade it!
		Consumable* _consumable = dynamic_cast<Consumable*>(purchasables[_indexToLook + _consumablesIndex]);
		do
		{
			if (_consumablesIndex < _indexToLook)
			{
				DISPLAY("Using consumable: " + _consumable->GetTypeName(), true);
				//Remove(&_consumable->type);
			}
			else
			{
				break;
			}
		} while (true);
	}
	else
	{
		string _noneOf = _category == 0 ? "aucune munitions" : "aucun consomable";
		DISPLAY(RED "[INFO] Tu ne possède " + _noneOf + RESET, true);
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

void Inventory::Add(const PurchasableType& _category, Purchasable* _purchase)
{
	const u_int& _inventorySize = InventorySize;
	Purchasable** _tempPurchasable = new Purchasable *[_inventorySize + 1];
	const u_int& _indexToAdd = GetPurchasablesSize(_category);
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
	allData[_category].count++;
}

bool Inventory::Remove(const PurchasableType& _purchaseType, const AllPurchasableType& _type)
{
	const u_int& _inventorySize = InventorySize;
	const u_int& _indexToRemove = GetIndexByType(_purchaseType, _type);

	if (_indexToRemove == _inventorySize) return false;

	// Todo Check index

	Purchasable** _tempPurchasable = new Purchasable * [_inventorySize - 1];
	bool _hasSkip = false;
	Purchasable* _purchase = nullptr;
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
	delete _purchase;
	delete purchasables;
	purchasables = _tempPurchasable;
	return true;
}

u_int Inventory::GetIndexByType(const PurchasableType& _purchaseType, const AllPurchasableType& _allType) const
{
	const u_int& _startIndex = _purchaseType - 1 < 0 ? 0 : GetPurchasablesSize(PurchasableType(_purchaseType-1));
	const u_int& _stopIndex = GetPurchasablesSize(_purchaseType);
	const int _typeValue = GetTypeValue(_purchaseType, _allType);
	for (u_int _i = _startIndex; _i < _stopIndex; _i++)
	{
		if (purchasables[_i]->GetType() == _typeValue)
		{
			return _i;
		}
	}
	return -1;
}

int Inventory::GetTypeValue(const PurchasableType& _purchaseType, const AllPurchasableType& _allType) const
{
	if (_purchaseType == PT_BULLET)
	{
		return _allType.bulletType;
	}
	else if (_purchaseType == PT_CONSUMABLE)
	{
		return _allType.consumableType;
	}
	return -1;
}
