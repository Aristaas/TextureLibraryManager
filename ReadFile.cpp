#include "ReadFile.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

//here is where we build the function (Body of class)
//This is the constructor code
ReadFile::ReadFile()
{
	fs::path dirProj = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/Projects";
	//const std::string* pdirProj = &dirProj;
	//std::cout << *pdirProj << std::endl; // this outputs the value and not the address
	fs::path dirLib = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/_Texture Library";
	std::string mfg;//variable that is the manufacturer name, found by reading the string inside the filename
	
	std::vector<fs::path> file;

	//std::string manufacturer = "tapis";
	//std::string spacerUS = "_";
	//std::string spacerSP = " ";
	//std::string spacerDA = "-";
	//std::string spacerCAP;//another spacer type can be a capital letter
	//std::string typeNm = "ultraleather";
	if (fs::exists(dirProj))
	{
		for (const auto& dirList : fs::recursive_directory_iterator(dirProj))
		{
			//std::cout << dirList.path() << std::endl; //this itterates through files
			file.emplace_back(dirList.path());//puts files into vector

				
			//std::cout << file.size() << std::endl; //prints file size
			//std::cout << dirList.path().filename() << std::endl; //prints filenames	
		}
		for (const auto& dirListProj : fs::recursive_directory_iterator(dirLib))//prints name of path
		{
			dirListProj.path();
		}

		for (unsigned int i = 0; i < file.size(); i++)
		{
			std::cout << file[i].filename() << std::endl;
			if (!fs::exists(file[i])) // CHANGE TO  if dirLib  exists then cycle through dir lib to see if file[i].filename exists without directory attached, may need to make a new vector with strings?
			{
				//fs::copy(dirList.path(), dirLib); //copies files to new directory
				fs::copy(file[i], dirLib); //copies files to new directory
			}
			else
			{
				std::cout << "File exists" << std::endl;
			}
			
		}
	}
	else
	{
		std::cout << "Directory does not exist";
	}
	//fs::copy(dirLib, dirProj);

}

//copy file x in directory dirProj
//paste file x om ddirectory dirLib