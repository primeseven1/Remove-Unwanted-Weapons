#include <windows.h>
#include <string>
#include <fstream>
#include "./ini.h"
#include "./logging.h"

uint8_t readFromINI()
{
	std::ifstream INI("RemoveUnwantedWeapons.ini");
	if (!INI.is_open()) 
		return VK_F6;

	std::string line;
	std::string value = "";
	while (std::getline(INI, line))
	{
		// Skip any lines that contain a comment, this will skip lines that have double slashes anywhere, but it's not a big deal
		if (line.find("//") != std::string::npos) 
			continue;

		if (line.find("key") != std::string::npos)
		{
			std::size_t pos = line.find("=");
			if (pos == std::string::npos)
				continue;

			value = line.substr(pos + 1);
			break;
		}
	}

	INI.close();

	// Return the default key if the key is invalid, or if the key option isn't found anywhere in the file and that would be logged
	int key;
	try
    {
		key = std::stoi(value, nullptr, 10);
    }
	catch (...)
	{
		genLogFile("Failed to set the key to specified value, setting it to the defualt");
		return VK_F6;
	}

	return (uint8_t)key;
}