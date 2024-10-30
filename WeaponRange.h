#pragma once
#include "Weapon.h"
#include "Bullet.h"
class WeaponRange : public Weapon
{
	int magazineSize;
	int currentMagazineSize;
	BulletType bulletType;

public:
	WeaponRange(const string& _name, const string& _description,const string& _skin,
		const int _buyingPrice, const float _accuracy,const int _magazineSize,
        const BulletType& _bulletType);
public:
	virtual void Attack() override;
};

