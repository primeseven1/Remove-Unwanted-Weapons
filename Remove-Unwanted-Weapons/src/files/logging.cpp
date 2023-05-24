#include <fstream>
#include <string>
#include <chrono>
#include <sstream>
#include <time.h>
#include <iomanip>

void genLogFile(const char* loggingInfo)
{
	// Open the file in append mode
	std::ofstream loggingFile("RemoveUnwantedWeapons.log", std::ios::app);
	if (!loggingFile.is_open())
		return;

	// Getting the current time to add to the file
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm timeInfo;
    localtime_s(&timeInfo, &currentTime);
    std::stringstream ss;
    ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

	loggingFile << loggingInfo << "\nTimestamp: " << ss.str() << "\n\n";
	loggingFile.close();
}
