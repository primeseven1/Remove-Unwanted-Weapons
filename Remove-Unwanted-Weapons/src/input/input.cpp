#include <ScriptHookV/natives.h>
extern "C"
{
    #include "./input.h"
    #include "./keyboard.h"
}

void awaitKeyPress(uint8_t key)
{
    while (1)
    {
        scriptWait(0);

        if (isKeyDown(key))
            return;
    }
}