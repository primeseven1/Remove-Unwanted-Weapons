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

uint8_t awaitKeyPress(std::vector<uint8_t> keys)
{
    while (1)
    {
        waitNextFrame();

        for (uint8_t key : keys)
        {
            if (isKeyDown(key))
                return key;
        }
    }
}