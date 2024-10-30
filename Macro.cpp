#include "Macro.h"

void Config()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

	locale::global(locale("fr-FR")); // UTF8
}