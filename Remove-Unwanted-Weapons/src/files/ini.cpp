#include <windows.h>
#include <string>
#include <fstream>
#include "./ini.h"
extern "C"
{
    #include "./logging.h"
}

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
			value = line.substr(pos + 1);
			break;
		}
	}

	INI.close();

	// Return the default key if the key is invalid, or if the key option isn't found anywhere in the file and that would be logged
	uint8_t key;
	try
    {
        key = (uint8_t)std::stoi(value, nullptr, 16);
    }
	catch(...)
	{
		genLogFile("There was an invalid argument for the key value, setting the key to the defualt value");
		return VK_F6;
	}

	return (uint8_t)key;
}