#include "MfgFromString.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

MfgFromString::MfgFromString(std::string projFilename)
	:fName(projFilename)
{
	//corian_adobe.tiff
	//corian adobe.tiff
	//corian-adobe.tiff
	//corian - adobe.tiff
	//corian adobe.psd
	//Corian_Adobe.tiff
//" ", "_", "-", " - ";
}

std::string MfgFromString::ReMfg()
{
	//fName
	int pos = fName.find_first_of(" _-");
	
	//test
	rettest = fName.substr (0, pos);
	return rettest;
}


/*
fs::path pathToString = dirList1[i].filename();
std::string stringFromPath = pathToString.u8string();
std::cout << stringFromPath << std::endl;
std::string a = stringFromPath;
MfgFromString fn(a);
std::string dirMfg = fn.ReMfg();
std::cout << dirMfg << std::endl;
//CreateDirFromName dirGen;

fs::path pathToStringLib = dirList2[0].parent_path();//taking library directory path and making it a string
std::string stringDromPathLib = pathToStringLib.u8string();
std::string b = stringDromPathLib;
fs::path p1 = b + "/" + dirMfg;//p1 is string that contains the new mfg folder name
fs::create_directory(p1);//creates new directory based on mfg
fs::copy(dirList1[i], p1, fs::copy_options::skip_existing);
//std::cout << "This file has been copied from: " << dirList1[i] << "to: " << dirList2[0].parent_path() << std::endl;
*/