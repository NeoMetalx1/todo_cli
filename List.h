#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

class List {
private:
    std::string path = "vaults";
    std::string user_task;
    std::string task_description;
    bool tick_task;
    nlohmann::json vaultList;
public:

    List(std::string name) {};

    void setUserTask(std::string& UserTask);
    void outUserTask();

    void setTaskDescription(std::string& TaskDescription);
    void outTaskDescription();

    void setCompleteStatus(bool status);
    void outCompleteStatus();

    void printAllLists();
};