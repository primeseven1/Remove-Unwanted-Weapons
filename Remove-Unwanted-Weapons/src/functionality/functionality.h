#pragma once

#ifdef __cplusplus

#include <ScriptHookV/main.h>
static inline void waitNextFrame() { scriptWait(0); }

#endif

#ifdef __cplusplus
extern "C"
{
#endif

void waitForStory();
void mainScript();

#ifdef __cplusplus
}
#endif