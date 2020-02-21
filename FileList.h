#pragma once
#ifndef READFILE_H
#define READFILE_H

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

//this file should inbclude function prototypes and variable definition (Tiles of class)
class FileList
{
public:
	FileList(fs::path a);
	std::vector<fs::path> List();
	std::vector<fs::path> file;
	~FileList();

private:
	fs::path pathToSearch;
};

#endif // !1
