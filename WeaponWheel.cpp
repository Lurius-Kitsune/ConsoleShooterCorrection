#include "WeaponWheel.h"

WeaponWheel::WeaponWheel()
{

}

WeaponWheel::~WeaponWheel()
{
	for (u_int _i = 0; _i < weaponsCount; _i++)
	{
		delete allWeapons[_i];
	}
	
	delete[] allWeapons;
}

void WeaponWheel::Display() const
{
	for (u_int _i = 0; _i < weaponsCount; _i++)
	{
		DISPLAY(allWeapons[_i]->ToString(), true);
	}
}

void WeaponWheel::AddWeapon(Weapon* _weapon)
{
	Weapon** _tempWeapons = new Weapon * [weaponsCount + 1];
	for (u_int _i = 0; _i < weaponsCount; _i++)
	{
		_tempWeapons[_i] = allWeapons[_i];
	}

	_tempWeapons[weaponsCount] = _weapon;
	delete allWeapons;
	allWeapons = _tempWeapons;
	weaponsCount++;
}

bool WeaponWheel::RemoveWeapon(Weapon* _weapon)
{
	if (_weapon)
	{
		Weapon** _tempWeapons = new Weapon * [--weaponsCount];
		bool _hasSkip = false;
		for (u_int _i = 0; _i < weaponsCount; _i++)
		{
			if (allWeapons[_i] == _weapon)
			{
				_hasSkip = true;
				continue;
			}
			_tempWeapons[_i] = allWeapons[_i + _hasSkip];
		}
		delete allWeapons;
		allWeapons = _tempWeapons;
		return true;
	}
	return false;
}

bool WeaponWheel::RemoveWeaponByIndex(const u_int& _index)
{
	return RemoveWeapon(GetWeaponByIndex(_index));
}

bool WeaponWheel::ConstainsWeapon(Weapon* _weapon) const
{
	return weaponsCount > 0;
}

bool WeaponWheel::IsValidIndex(const u_int& _index) const
{
	return _index >= 0 && _index < weaponsCount;
}

Weapon* WeaponWheel::GetWeaponByIndex(const u_int& _index) const
{
	if (!IsValidIndex(_index)) return nullptr;
	return allWeapons[_index];
}

Weapon* WeaponWheel::GetWeaponByName(const string& _name) const
{
	for (u_int _i = 0; _i < weaponsCount; _i++)
	{
		if (allWeapons[_i] == )
		{
			_hasSkip = true;
			continue;
		}
		_tempWeapons[_i] = allWeapons[_i + _hasSkip];
	}
	return allWeapons[_index];
}
