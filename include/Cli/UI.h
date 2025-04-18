#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../Json/Json.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#define VERSION "v0.1.1"

class UI {
private:
    std::string vaultPath = "vault/";
    std::vector<std::string> vaultListScan(const std::string& vaultPath);
    std::vector<std::string> vaultList;
public:

    UI();
    void printAllTasks();
    void printSpecifiedTask(const std::string& taskName);
    void waitForEnter();
    void clearScreen();
    void helpMenu();
    void versionMenu();
    void cliMainMenu(); 
    void printLogo();

};