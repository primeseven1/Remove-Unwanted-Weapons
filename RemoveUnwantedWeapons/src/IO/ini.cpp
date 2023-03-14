#include "../Precompiled_Headers/pch.h"
#include "ini.h"
#include "iostream"

int readFromINI()
{
	// Return the default key if the file can't be opened
	std::ifstream INI("RemoveUnwantedWeapons.ini");
	if (!INI.is_open()) return VK_F6;

	std::string line;
	std::string value = "";
	while (std::getline(INI, line))
	{
		if (line.find("//") != std::string::npos) continue;
		// Goes through the file until it finds key
		if (line.find("key") != std::string::npos)
		{
			std::size_t pos = line.find("=");
			value = line.substr(pos + 2);
			break;
		}
	}

	// Return the default if the key is invalid
	int key;
	try
	{
		key = std::stoi(value, nullptr, 16);
		if (key > 256 || key < 1) return VK_F6;
	}
	catch(...)
	{
		return VK_F6;
	}

	return key;
}