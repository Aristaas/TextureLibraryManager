#include "compare2Vectors.h"
#include "FileList.h"
#include "MfgFromString.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

std::string g_askTextProj = "Enter the path to the PROJECT folder\nFor first time use, use the root of ALL projects (This may take a while)";
std::string g_askTextLib = "Enter the path to the LIBRARY folder";

int main()
{
	//user input project folder
	std::cout << g_askTextProj << std::endl;
	std::string cin_dirProj;
	std::getline(std::cin, cin_dirProj);
	fs::path dirProj = cin_dirProj;
	
	//user input library folder
	std::cout << g_askTextLib << std::endl;
	std::string cin_dirLib;
	std::getline(std::cin, cin_dirLib);
	fs::path dirLib = cin_dirLib;

	FileList checkProj(dirProj), checkLib(dirLib);
	std::vector<fs::path> dirList1 = checkProj.List();//list of files in project directory
	std::vector<fs::path> dirList2 = checkLib.List();//list of files in library directory
	
	Compare2Vectors projLib(dirList1, dirList2, dirLib);//copies files into folders
	projLib.Compare();
}