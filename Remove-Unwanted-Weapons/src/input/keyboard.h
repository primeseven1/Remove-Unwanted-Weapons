#pragma once

#include <windows.h>
#include <stdbool.h>
#include <stdint.h>

void onKeyboardMessage(
    DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, 
    BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow );
bool isKeyDown(uint8_t key);
bool isKeyJustUp(uint8_t key, bool exclusive);