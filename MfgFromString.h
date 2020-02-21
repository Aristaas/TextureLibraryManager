#pragma once
//#ifndef READFILE_H
//#define READFILE_H

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class MfgFromString
{
public:
	MfgFromString(std::string projFilename);
	std::string ReMfg();
	std::string rettest;

private:
	std::string fName;
	//const std::string symbols = " _-";
};

//#endif // !1

