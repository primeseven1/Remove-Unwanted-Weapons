#include "../Precompiled_Headers/pch.h"

void genLogFile(const char* loggingInfo)
{
	// Open the file in append mode
	std::ofstream loggingFile("RemoveUnwantedWeapons.log", std::ios::app);
	if (!loggingFile.is_open()) return;

	loggingFile << loggingInfo << "\n";
	loggingFile.close();
}
