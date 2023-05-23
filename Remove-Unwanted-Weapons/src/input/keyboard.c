/*
		THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
					http://dev-c.com
				(C) Alexander Blade 2015
*/

/*
    Changes I made:
        - Now a .c file
        - Made some preprocessor defintions instead of variables
        - Made some symbols have internal linkage instead of external

*/

#include "./keyboard.h"

#define KEYS_SIZE 255

static struct 
{
	DWORD time;
	BOOL isWithAlt;
	BOOL wasDownBefore;
	BOOL isUpNow;
} keyStates[KEYS_SIZE];

// Disable the warning msvc gives for GetTickCount, since i doubt most people are running gta 5 for 49 days straight
#pragma warning(disable : 28159)

void onKeyboardMessage(
    DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, 
    BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow )
{
	if (key < KEYS_SIZE)
	{
		keyStates[key].time = GetTickCount();
		keyStates[key].isWithAlt = isWithAlt;
		keyStates[key].wasDownBefore = wasDownBefore;
		keyStates[key].isUpNow = isUpNow;
	}
}

// milliseconds
#define NOW_PERIOD 100
#define MAX_DOWN 5000

bool isKeyDown(uint8_t key)
{
	return (key < KEYS_SIZE) ? ((GetTickCount() < keyStates[key].time + MAX_DOWN) && !keyStates[key].isUpNow) : false;
}

static void resetKeyState(uint8_t key)
{
	if (key < KEYS_SIZE)
		memset(&keyStates[key], 0, sizeof(keyStates[0]));
}

bool isKeyJustUp(uint8_t key, bool exclusive)
{
	bool up = (key < KEYS_SIZE) ? (GetTickCount() < keyStates[key].time + NOW_PERIOD && keyStates[key].isUpNow) : false;
	if (up && exclusive)
		resetKeyState(key);

	return up;
}