#include "../Precompiled_Headers/pch.h"
#include "../IO/keyboard.h"
#include "scriptMain.h"

static void waitForStory()
{
	// The story has loaded once the player entity exists
	while (!ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
	{
		scriptWait(0);
		continue; 
	}
}

void scriptMain()
{
	waitForStory();
	keyboardHandler();
}
