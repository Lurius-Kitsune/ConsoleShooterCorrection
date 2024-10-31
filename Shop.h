#pragma once
#include "Player.h"
class Shop
{
	Weapon** weapons;
	u_int weaponsCount;
	Inventory* inventory;
	Player* player;

public:
	Shop();
	~Shop();

public:
	void Open(Player* _player);

private:
	// Weapon
	Weapon* SellWeapons();
	string* GetWeaponsName() const;

	Purchasable* Sell(const PurchasableType& _purchaseType);

	//Bullet
	Bullet* SellBullets();

	//Consumable
	Consumable* SellConsumable();


	//PurchsableItem
	string* GetPurchasableItemsNameByType(const PurchasableType& _purchaseType, u_int& _arrayCount) const;

	void Close();
};

