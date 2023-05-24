#include <ScriptHookV/natives.h>
#include "../functionality/functionality.h"
#include "./input.h"
#include "./keyboard.h"

void awaitKeyPress(uint8_t key)
{
    while (1)
    {
        waitNextFrame();

        if (isKeyDown(key))
            return;
    }
}