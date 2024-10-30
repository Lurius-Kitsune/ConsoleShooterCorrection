#include "WeaponWheel.h"

WeaponWheel::WeaponWheel()
{
	weaponsCount = 0;
	allWeapons = new Weapon * [weaponsCount];
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

bool WeaponWheel::AddWeapon(Weapon* _weapon)
{
	if (ContainsWeapon(_weapon)) return false;

	Weapon** _newArray = new Weapon * [weaponsCount + 1];

	for (u_int _index = 0; _index < weaponsCount; _index++)
	{
		_newArray[_index] = allWeapons[_index];
	}

	_newArray[weaponsCount] = _weapon;
	delete[] allWeapons;
	allWeapons = _newArray;
	weaponsCount++;

	return true;
}

bool WeaponWheel::RemoveWeapon(Weapon* _weapon)
{
	if (!_weapon || !ContainsWeapon(_weapon)) return false;

    Weapon** _newArray = new Weapon*[--weaponsCount];
    bool _hasSkip = false;

    for (u_int _index = 0; _index < weaponsCount; _index++)
    {
        if (!_hasSkip && *_weapon == *allWeapons[_index])
        {
            _hasSkip = true;
        }
        _newArray[_index] = allWeapons[_index + _hasSkip];
    }

    delete _weapon;
    delete[] allWeapons;
    allWeapons = _newArray;

    return true;
}

bool WeaponWheel::RemoveWeaponByIndex(const u_int& _index)
{
	return RemoveWeapon(GetWeaponByIndex(_index));
}

bool WeaponWheel::ContainsWeapon(Weapon* _weapon) const
{
	return GetWeaponByName(_weapon->GetName());
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
		if (allWeapons[_i]->GetName() == _name)
		{
			return allWeapons[_i];
		};
	}
	return nullptr;
}
