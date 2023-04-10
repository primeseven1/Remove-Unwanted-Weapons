#include "../Precompiled_Headers/pch.h"
#include "ini.h"
#include "logging.h"

unsigned int readFromINI()
{
	// Return the default key if the file can't be opened for some reason
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

		// Goes through the file until it finds the first value matching key
		// If there is more than one key value, it will just use the first one whether it's valid or not, if it's not valid it's just going to use F6
		if (line.find("key") != std::string::npos)
		{
			std::size_t pos = line.find("=");
			value = line.substr(pos + 1);
			break;
		}
	}

	INI.close();

	// Return the default key if the key is invalid, or if the key option isn't found anywhere in the file and that would be logged
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

	// A key that is 0 or negative is not a valid key, and the key would just be set to the defualt
	return (unsigned int)key;
}
