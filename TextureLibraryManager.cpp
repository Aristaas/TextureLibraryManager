// TextureLibraryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "FileList.h"
#include "MfgFromString.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

//fs::path g_dirProj = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/Projects/";
//fs::path g_dirLib = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/_Texture Library/";

int main()
{

	//user input project folder
	std::cout << "Enter the path to the PROJECT folder" << std::endl << "For first time use, use the root of ALL projects (THis may take a while)" << std::endl;
	std::string cin_dirProj;
	std::getline(std::cin, cin_dirProj);
	fs::path g_dirProj = cin_dirProj;
	
	//user input library folder
	std::cout << "Enter the path to the LIBRARY folder" << std::endl;
	std::string cin_dirLib;
	std::getline(std::cin, cin_dirLib);
	fs::path g_dirLib = cin_dirLib;
	std::cout << g_dirLib << std::endl;

	FileList checkProj(g_dirProj), checkLib(g_dirLib);
	std::vector<fs::path> dirList1 = checkProj.List();//list of files in project directory
	std::vector<fs::path> dirList2 = checkLib.List();//list of files in library directory

	if (!dirList1.empty())//if project dir is not empty
	{
		fs::path x, y;//allows comparison of two filenames	
		for (unsigned int i = 0; i < dirList1.size(); i++) //iterates through the list from project dir
		{
			x = dirList1[i].filename();
			bool fileExists = false;

			for (unsigned int j = 0; j < dirList2.size(); j++)//iterates through the list from library dir
			{
				y = dirList2[j].filename();
				
				if (x == y) //if both filenames are equal, loops through the library list until the end
				{
					fileExists = true;
					break; //doesn't need to keep cheking if file was found
				}
				else
				{
					fileExists = false;
				}
			}

			if (!fileExists)
			{
				MfgFromString fn(dirList1[i]);
				std::string dirMfg = fn.ReMfg();
				//std::cout << dirMfg << std::endl;

				std::string stringDromPathLib = g_dirLib.u8string();//create a string from the library path
				fs::path p1 = stringDromPathLib + "/" + dirMfg;//p1 is string that contains the new mfg folder name
				fs::create_directory(p1);//creates new directory based on mfg
				fs::copy(dirList1[i], p1, fs::copy_options::skip_existing);
			}
		}
	}
	else
	{
		std::cout << "Directory does not exist or there are no files in directory";
	}
}