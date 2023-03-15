// dllmain.cpp : Defines the entry point for the DLL application.
#include "./Precompiled_Headers/pch.h"
#include "./Main/scriptMain.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        scriptRegister(hModule, scriptMain);
        keyboardHandlerRegister(OnKeyboardMessage);
        break;

    case DLL_PROCESS_DETACH:
        scriptUnregister(scriptMain);
        keyboardHandlerUnregister(OnKeyboardMessage);
        break;
    }
    
    return TRUE;
}
