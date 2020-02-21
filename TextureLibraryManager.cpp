// TextureLibraryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.

//#include "ReadFile.h"
#include "FileList.h"
#include "MfgFromString.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

fs::path dirProj = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/Projects/";
fs::path dirLib = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/_Texture Library/";

int main()
{
	FileList checkProj(dirProj), checkLib(dirLib);
	std::vector<fs::path> dirList1 = checkProj.List();
	std::vector<fs::path> dirList2 = checkLib.List();
	//std::cout << dirList1.size() << std::endl;
	//std::cout << dirList2.size() << std::endl;

	if (!dirList1.empty())
	{
		fs::path x, y;
		for (unsigned int i = 0; i < dirList1.size(); i++)
		{
			x = dirList1[i].filename();
			bool fileExists = false;
			//std::cout << "This is the projfile element #" << i << ". " << " This is checking the filename " << x << std::endl;
			for (unsigned int j = 0; j < dirList2.size(); j++)
			{
				y = dirList2[j].filename();
				
				//std::cout << x << y << std::endl;
				if (x == y)
				{
					fileExists = true;
					//std::cout << " File already exists: " << dirList2[j].filename() << std::endl;
					//a choice should be given, either copy to a new folder, overwrite, or skip.
					//only tiffs
					break;
				}
				else
				{
					fileExists = false;
				}
			}
			//if (dirList2.size() == 0) { fileExists = false; }
			if (!fileExists)
			{
				fs::path pathToString = dirList1[i].filename();
				std::string stringFromPath = pathToString.u8string();
				std::cout << stringFromPath << std::endl;
				std::string a = stringFromPath;
				MfgFromString fn(a);
				std::string dirMfg = fn.ReMfg();
				std::cout << dirMfg << std::endl;
				//CreateDirFromName dirGen;

				fs::path pathToStringLib = dirLib;//taking library directory path and making it a string
				std::string stringDromPathLib = pathToStringLib.u8string();
				std::string b = stringDromPathLib;
				fs::path p1 = b + "/" + dirMfg;//p1 is string that contains the new mfg folder name
				fs::create_directory(p1);//creates new directory based on mfg
				fs::copy(dirList1[i], p1, fs::copy_options::skip_existing);
				//std::cout << "This file has been copied from: " << dirList1[i] << "to: " << dirList2[0].parent_path() << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Directory does not exist or there are no files in directory";
	}



}
