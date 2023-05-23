#include <ScriptHookV/natives.h>
#include <windows.h>
extern "C" 
{
    #include "./main.h"
    #include "./input/keyboard.h"
}

BOOL APIENTRY DllMain( 
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        scriptRegister(hModule, main);
        keyboardHandlerRegister(onKeyboardMessage);
        break;

    case DLL_PROCESS_DETACH:
        scriptUnregister(hModule);
        keyboardHandlerUnregister(onKeyboardMessage);
        break;
    }
    return TRUE;
}