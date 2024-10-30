#include "WeaponRange.h"

WeaponRange::WeaponRange(const string& _name, const string& _description,
	const string& _skin, const int _buyingPrice, const float _accuracy,
	const int _magazineSize,const BulletType& _bulletType)
	: Weapon(_name, _description, _skin, _buyingPrice, _accuracy)
{
	magazineSize = _magazineSize;
	currentMagazineSize = _magazineSize;
	bulletType = _bulletType;
}

void WeaponRange::Attack()
{
	// TODO
	DISPLAY("Attaque distance !", true);
}
