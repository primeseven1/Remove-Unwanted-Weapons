#ifndef PCH_H
#define PCH_H

#pragma region Windows API

#include <Windows.h>

#pragma endregion

#pragma region SDK

#include <include/ScriptHookV/enums.h>
#include <include/ScriptHookV/main.h>
#include <include/ScriptHookV/nativeCaller.h>
#include <include/ScriptHookV/natives.h>
#include <include/ScriptHookV/sdkKeyboard.h>
#include <include/ScriptHookV/types.h>

#pragma endregion

#pragma region STL

#include <fstream>
#include <unordered_map>
#include <string>

#pragma endregion

#endif //PCH_H
