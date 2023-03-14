#include "../Precompiled_Headers/pch.h"
#include "keyboard.h"
#include "ini.h"

void keyboardHandler()
{
	int key = readFromINI();

	while (1)
	{
		// Wait for the next frame
		scriptWait(0);

		if (GetKeyState(key) & KEY_PRESSED)
		{
			Ped playerPedId = PLAYER::PLAYER_PED_ID();
			Hash weapon = WEAPON::GET_SELECTED_PED_WEAPON(playerPedId);

			// Do nothing if the selected weapon is unarmed
			if (weapon == WeaponUnarmed) continue;

			/* Remove the currently selected weapon, and set it to unarmed,
			also a way of preventing multiple weapons from being removed at once */
			WEAPON::REMOVE_WEAPON_FROM_PED(playerPedId, weapon);
			WEAPON::SET_CURRENT_PED_WEAPON(playerPedId, WeaponUnarmed, TRUE);
		}
	}
}