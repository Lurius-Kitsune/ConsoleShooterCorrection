#pragma once
#include "Weapon.h"
#include "Bullet.h"
class WeaponRange : public Weapon
{
	int magazineSize;
	int currentMagazineSize;
	BulletType bulletType;

public:

public:
	virtual void Attack() override;
};

