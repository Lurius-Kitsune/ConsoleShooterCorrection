#pragma once
#include "Weapon.h"
class WeaponMelee : public Weapon
{
	float criticalLuck;
	float criticDamages;
	int damages;

public:

public:
	virtual void Attack() override;
};

