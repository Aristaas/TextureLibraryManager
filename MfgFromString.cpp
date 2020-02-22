#include "MfgFromString.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

MfgFromString::MfgFromString(std::string projFilename)
	:a_fName(projFilename)// I would rather have the conversion from path to file inside the class
{
}

std::string MfgFromString::ReMfg()
{
	int pos = a_fName.find_first_of(" _-");
	
	a_retManufacturer = a_fName.substr (0, pos);
	return a_retManufacturer;
}