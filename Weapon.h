#pragma once
#include "UserInteract.h"

class Weapon
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

	string GetSkin()const
	{
		return skin;
	}

	//Weapon() = default;
	Weapon(const string& _name, const string& _description, const string& _skin,
		const int _buyingPrice, const float _accuracy);

public: 
	virtual void Attack(){};
	virtual string ToString()const;
	virtual void Drop();

	bool operator == (const Weapon& _other);
};

