#include "MfgFromString.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

MfgFromString::MfgFromString(fs::path projFilename)
	:a_fName(projFilename)// I would rather have the conversion from path to file inside the class
{
}

std::string MfgFromString::ReMfg()
{
	stringFromPath = a_fName.filename().u8string();
	int pos = stringFromPath.find_first_of(" _-");
	
	a_retManufacturer = stringFromPath.substr (0, pos);
	return a_retManufacturer;
}