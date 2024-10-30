#pragma once
#include "Purchasable.h"
class Weapon : public Purchasable
{
	string name;
	string description;
	int purchasePrice;
	string skin; // color
	float accuracy;

public:

	string GetName()const
	{
		return name;
	}

	//Weapon() = default;
	Weapon(const string& _name, const string& _description, const string& _skin,
		const int _buyingPrice, const float _accuracy);

public: 
	virtual void Attack() = 0;
	virtual string ToString();
	virtual void Drop();

	bool operator == (const Weapon& _other);
};

