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

	// Return the default key if the key is invalid
	int key;
	try
    {
		key = std::stoi(value, nullptr, 10);
    }
	catch (const std::exception& exception)
	{
		std::string message = "Failed to set the key to the specified value\nException:" + static_cast<std::string>(exception.what());
		genLogFile(message.c_str()); 
		return VK_F6;
	}

	// Max VK key count is 255
	if (key > UINT8_MAX)
	{
		genLogFile(
			"Failed to set the key to the specified value\n"
			"Value is bigger than 255");

		return VK_F6;
	}

	return static_cast<uint8_t>(key);
}