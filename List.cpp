#include "List.h"

/*================Getters And Setters=====================*/

void List::setUserTask(std::string& UserTask) {
    user_task = UserTask;
}

void List::outUserTask() {
    std::cout << "[+] " << user_task << std::endl;
}

void List::setTaskDescription(std::string& TaskDescription) {
    task_description = TaskDescription;
}

void List::outTaskDescription() {
    std::cout << "    - " << task_description << std::endl;
}

void List::setCompleteStatus(bool status) {
    tick_task = status;
}

void List::outCompleteStatus() {
    if (tick_task = true) {
        std::cout << "\t--- Task Complition Status: Completed! ---" << std::endl << std::endl << std::endl;
    } else {
        std::cout << "\t--- Task Complition Status: Not completed! ---" << std::endl << std::endl << std::endl;
    }
}   

void List::printAllLists() {
    nlohmann::json vaultList = nlohmann::json::array();

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file() && entry.path().extension() == "") {
            vaultList.push_back(entry.path().filename().string());
        }
    }

    std::ofstream outputFile("vaultsLists/vaultsList");
    outputFile << vaultList.dump(4) << std::endl;
    outputFile.close();

    std::cout << vaultList.dump(4) << std::endl << std::endl;
}

void List::vaultDelete(std::string vaultName) {
    std::filesystem::path targetVault = path + vaultName;
    try {
        if (std::filesystem::remove(targetVault)) {
            std::cout << "Task deleted! :(" << std::endl;
        } else {
            std::cout << "Task not found! Make sure name is correct" << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}