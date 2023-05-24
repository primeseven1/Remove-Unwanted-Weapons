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

	// Get the time so that it can be logged to the file
	auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm timeInfo;
	localtime_s(&timeInfo, &currentTime);
	std::stringstream ss;
	ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S"); // Formatting as a string

	loggingFile << loggingInfo << "| Time:" << ss.str() << "\n";
	loggingFile.close();
}
