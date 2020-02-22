#include "FileList.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

//this class iteritively searches a folder and all its directories and pushes it into a vector
FileList::FileList(fs::path a)
	: a_pathToSearch(a)
{
}

std::vector<fs::path> FileList::List()
{
	//if file contains .tiff
	//if (dirList.path().filename().extension() == ".tiff")
	//{

	//}
	if (fs::exists(a_pathToSearch)) //if inputed path exists
	{
		for (const auto& dirList : fs::recursive_directory_iterator(a_pathToSearch))//iterates through files and...
		{
			if (dirList.path().filename().extension() == ".tif")
			{
				a_file.emplace_back(dirList.path());//puts files into vector
			}
		}
	}
	else
	{
		a_file.clear();//clears vector, vector becomes file[0]
	}
	return a_file;
}

//deconstructor, I don't even know it I need this!
FileList::~FileList()
{
}
