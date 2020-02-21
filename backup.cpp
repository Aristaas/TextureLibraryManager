// TextureLibraryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

int main()
{
    //vars
    std::string libPath = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/Projects";
    std::ofstream outfile;
    //output

    outFile.open("G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/Projects/Filetest.txt")
        //figure out if I can use + to join var and file name

        outFile << "This is my first line" << std::endl << "This is my second line.";

    outFile.close();


    for (const auto& dirEntry : recursive_directory_iterator(libPath))
        std::cout << "hello" << std::endl << dirEntry.path() << std::endl;
    /*
    std::string libPath = "G:/Projects/Scripting - TextureLibraryManager - 0.0.1/Test folders/Projects";
    for (const auto& entry : fs::directory_iterator(libPath))
        std::cout << entry.path() << std::endl;
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
