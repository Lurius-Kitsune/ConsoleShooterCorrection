#include "WeaponWheel.h"
#include "WeaponRange.h"

int main()
{
    Config();
    //DisplayRainbow("coucou <3");

    WeaponWheel _wheel;
    Weapon* _weapon = new WeaponRange("AK-47", "Pan-Pan", BLINK_TEXT  RED, 1000, 12.2f, 10, BT_PARTITION_BULLET);
    _wheel.AddWeapon(_weapon);
    _wheel.RemoveWeapon(_weapon);

    return EXIT_SUCCESS;
}

