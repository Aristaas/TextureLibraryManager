#pragma once

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class MfgFromString
{
public:
	MfgFromString(std::string projFilename);
	std::string ReMfg();

private:
	std::string a_fName;
	std::string a_retManufacturer;
};