#include "../Precompiled_Headers/pch.h"
#include "ini.h"
#include "logging.h"

unsigned int readFromINI()
{
	// Return the default key if the file can't be opened
	std::ifstream INI("RemoveUnwantedWeapons.ini");
	if (!INI.is_open()) 
		return VK_F6;

	std::string line;
	std::string value = "";
	while (std::getline(INI, line))
	{
		// Skip any lines that contain a comment
		if (line.find("//") != std::string::npos) 
			continue;

		// Goes through the file until it finds key
		if (line.find("key") != std::string::npos)
		{
			std::size_t pos = line.find("=");
			value = line.substr(pos + 1);
			break;
		}
	}

	INI.close();

	// Return the default key if the key is invalid, and if the key option isn't found anywhere
	int key;
	try
	{
		key = std::stoi(value, nullptr, 16);
		if (key > 255 || key < 1)
		{
			genLogFile("Invalid key in the INI file, setting the key to the default value.");
			return VK_F6;
		}
	}
	catch(...)
	{
		genLogFile("There was an error when setting the key in the INI file, setting the key to the default value");
		return VK_F6;
	}

	return (unsigned int)key;
}
