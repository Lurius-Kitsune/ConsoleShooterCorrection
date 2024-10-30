#include "WeaponWheel.h"
#include "WeaponRange.h"
#include "Shop.h"

int main()
{
    Config();
    //DisplayRainbow("coucou <3");

    WeaponWheel _wheel;
    Weapon* _weapon = new WeaponRange("AK-47", "Pan-Pan", BLINK_TEXT  RED, 1000, 12.2f, 10, BT_PARTITION_BULLET);
    _wheel.AddWeapon(_weapon);
    _wheel.RemoveWeapon(_weapon);

   
    u_int _purchasesCount = 0;
    Purchasable** _purchases = new Purchasable * [_purchasesCount];

    Shop _shop;
    _shop.Open(_purchases, _purchasesCount);

    delete[] _purchases;
    return EXIT_SUCCESS;
}

