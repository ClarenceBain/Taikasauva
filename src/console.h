#ifndef TITLE_H
#define TITLE_H

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dirent.h"


void title() // cheesy fun
{
    std::cout << "  _______    _ _                                     " << std::endl;
    std::cout << " |__   __|  (_) |                                    " << std::endl;
    std::cout << "    | | __ _ _| | ____ _ ___  __ _ _   ___   ____ _  " << std::endl;
    std::cout << "    | |/ _` | | |/ / _` / __|/ _` | | | \\ \\ / / _` | " << std::endl;
    std::cout << "    | | (_| | |   < (_| \\__ \\ (_| | |_| |\\ V / (_| | " << std::endl;
    std::cout << "    |_|\\__,_|_|_|\\_\\__,_|___/\\__,_|\\__,_| \\_/ \\__,_| " << std::endl;
}

void init(LPCWSTR consoleTitle)
{
    AllocConsole();
    SetConsoleTitle(consoleTitle);
    FILE* file;
    freopen_s(&file, "CONOUT$", "w", stdout);
    freopen_s(&file, "CONIN$", "r", stdin);
    title();
}

void displayFiles()
{
    //d = opendir("taikasauva\\*.tai")
    DIR* dir;
    struct dirent* directory;
    dir = opendir("taikasauva\\");
    if (dir)
    {
        std::cout << "\n" << std::endl;
        while ((directory = readdir(dir)) != NULL)
        {
            if (std::strstr(directory->d_name, ".tai")) {
                std::cout << directory->d_name << std::endl;
            }
        }
        closedir(dir);
    }
}

void openFile(std::string path) {
    std::string line;
    std::ifstream myfile(path);
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            wandScript = line;
        }
        myfile.close();
    }
}
#endif
