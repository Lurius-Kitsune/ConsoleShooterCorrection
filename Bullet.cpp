#include "Bullet.h"

Bullet::Bullet(const BulletType& _type)
{
	type = _type;
}

string Bullet::GetTypeName() const
{
	switch (type)
	{
	case BT_HOLLOW_POINT:
		return "HOLLOW_POINT";

	case BT_BOAT_TAIL:
		return "BOAT_TAIL";

	case BT_ARROW:
		return "ARROW";

	case BT_JACKETED_HOLLOW_POINT:
		return "JACKETED_HOLLOW_POINT";

	case BT_ROUND_NOSE:
		return "ROUND_NOSE";

	case BT_PARTITION:
		return "PARTITION";

	default:
		break;
	}

	return "Unknown";
}
