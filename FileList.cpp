#include "FileList.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

//this class iteritively searches a folder and all its directories and pushes it into a vector
FileList::FileList(fs::path a)
	: pathToSearch(a)
{

}

std::vector<fs::path> FileList::List()
{
	if (fs::exists(pathToSearch))
	{
		//std::cout << "path: " << pathToSearch << std::endl;
		for (const auto& dirList : fs::recursive_directory_iterator(pathToSearch))//iterates through files and...
		{
			file.emplace_back(dirList.path());//puts files into vector
			
		}
	}
	else
	{
		file.clear();
	}
	return file;
}

//deconstructor
FileList::~FileList()
{

}
