#include "Compare2Vectors.h"
#include "MfgFromString.h"
#include "FileList.h"
#include <iostream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;


//Compares two lists and copies
Compare2Vectors::Compare2Vectors(std::vector<fs::path> a, std::vector<fs::path> b, fs::path c)
	: a_list1(a), a_list2(b), a_LibLoc(c)
{
}

void Compare2Vectors::Compare()
{
	if (!a_list1.empty())//if project dir is not empty
	{
		fs::path x, y;//allows comparison of two filenames	
		for (unsigned int i = 0; i < a_list1.size(); i++) //iterates through the list from project dir
		{
			x = a_list1[i].filename();
			bool fileExists = false;

			for (unsigned int j = 0; j < a_list2.size(); j++)//iterates through the list from library dir
			{
				y = a_list2[j].filename();

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
				MfgFromString fn(a_list1[i]);
				std::string dirMfg = fn.ReMfg();
				//std::cout << dirMfg << std::endl;

				std::string stringDromPathLib = a_LibLoc.u8string();//create a string from the library path
				fs::path p1 = stringDromPathLib + "/" + dirMfg;//p1 is string that contains the new mfg folder name
				fs::create_directory(p1);//creates new directory based on mfg
				fs::copy(a_list1[i], p1, fs::copy_options::skip_existing);
			}
		}
	}
	else
	{
		std::cout << "Directory does not exist or there are no files in directory";
	}
}
