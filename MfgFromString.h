#pragma once

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class MfgFromString
{
public:
	MfgFromString(fs::path projFilename);
	std::string ReMfg();
	std::string stringFromPath;

private:
	fs::path a_fName;
	std::string a_retManufacturer;
};