#include <ScriptHookV/natives.h>
#include <ScriptHookV/enums.h>
#include "../files/ini.h"
#include "./functionality.h"
#include "../input/input.h"

static void removeCurrentPlayerWeapon()
{
    Ped playerPedId = PLAYER::PLAYER_PED_ID();
    Hash weapon = WEAPON::GET_SELECTED_PED_WEAPON(playerPedId);

    // Do nothing if the selected weapon is unarmed
    if (weapon == WeaponUnarmed) 
        return;

    // Setting the ped weapon to unarmed removes the need for some kind of cooldown
    WEAPON::REMOVE_WEAPON_FROM_PED(playerPedId, weapon);
    WEAPON::SET_CURRENT_PED_WEAPON(playerPedId, WeaponUnarmed, TRUE);   
}

void waitForStory()
{
    // By checking for the player's existance in the game, that's how it knows that the game has loaded
    // That also prevents a crash if you press the selected key when the game hasn't loaded the story yet
    while (!ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
	waitNextFrame();
}

void mainScript()
{
    uint8_t key = readFromINI();

    while (1)
    {
        waitNextFrame();
        awaitKeyPress(key);
        removeCurrentPlayerWeapon();
    }
}
