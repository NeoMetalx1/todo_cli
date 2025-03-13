#pragma once

#include <iostream>

class List {
private:
    std::string user_task;
    std::string task_description;
    bool tick_task;
public:

    void setUserTask(std::string& UserTask);
    void outUserTask();

    void setTaskDescription(std::string& TaskDescription);
    void outTaskDescription();

    void setCompleteStatus(bool status);
    void outCompleteStatus();
};