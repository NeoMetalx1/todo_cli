#pragma once

#include <iostream>
#include <vector>
#include "../Json/Json.h"

class CLI_GUI {
private:
    std::string vaultPath = "vault/";
    std::vector<std::string> vaultListScan(const std::string& vaultPath);
    std::vector<std::string> vaultList;
public:

    CLI_GUI();
    void printTasks();
    void helpMenu();
    void versionMenu();

};