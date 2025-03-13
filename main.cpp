#include <iostream>
#include "List.h"

int main() {
    List todo_list;
    std::string list = "Write own todo list";
    todo_list.setUserTask(list);
    todo_list.outUserTask();

    std::string TaskDescription = "Lorem ipsum i pupu balala, tratata burtata jukevic";
    todo_list.setTaskDescription(TaskDescription);
    todo_list.outTaskDescription();

    bool taskStatus = true;
    todo_list.setCompleteStatus(taskStatus);
    todo_list.outCompleteStatus();


    List ideas_list;
    std::string ideas_list_name = "Ideas list";
    todo_list.setUserTask(ideas_list_name);
    todo_list.outUserTask();

    std::string ideas_list_description = "Lorem ipsum i pupu balala, tratata burtata jukevic hydashdaysh dsdyhashdya ahdaydhasyd dhadyadhyas";
    todo_list.setTaskDescription(ideas_list_description);
    todo_list.outTaskDescription();

    bool ideas_list_status = false;
    todo_list.setCompleteStatus(ideas_list_status);
    todo_list.outCompleteStatus();
}