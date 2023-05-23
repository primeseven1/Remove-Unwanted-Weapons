#include <stdio.h>
#include <time.h>
#include "./logging.h"

void genLogFile(const char* loggingInfo)
{
    FILE* file = NULL;

    if (fopen_s(&file, "RemoveUnwantedWeapons.log", "a") != 0)
        return;

    time_t currentTime;
    time(&currentTime);
    struct tm timeInfo;
    localtime_s(&timeInfo, &currentTime);

    // Format timestamp
    char timestamp[50];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S\n", &timeInfo);

    fprintf_s(file, "%s | Time: %s", loggingInfo, timestamp);
    fclose(file);
}