#include "WeaponWheel.h"
#include "WeaponRange.h"
#include "Shop.h"

int main()
{
    Config();
    //DisplayRainbow("coucou <3");

    WeaponWheel _wheel;
    Weapon* _weapon = new WeaponRange("AK-47", "Pan-Pan", BLINK_TEXT  RED, 1000, 12.2f, 10, BT_PARTITION);
    _wheel.AddWeapon(_weapon);
    _wheel.RemoveWeapon(_weapon);

    Player* _player = new Player();

    Shop _shop;
    //_shop.Open(_player);

    const string _menu[] =
    {
        "Shop",
        "Inventory"
    };

	u_int _menuCount = size(_menu);
    do
    {
        int _menuIndex = OpenMenu(_menu, _menuCount, "Que Faire ?");
        CLEAR_SCREEN;
		if (_menuIndex == 0)
		{
			_shop.Open(_player);
		}
		else if (_menuIndex == 1)
		{
			_player->GetInventory()->Open();
		}
		else
		{
			break;
		}
    } while (true);
    delete _player;
    return EXIT_SUCCESS;
}

