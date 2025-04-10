#include "../../include/Cli/Cli.h"

CLI_GUI::CLI_GUI() {
    vaultList = vaultListScan(vaultPath);
}

std::vector<std::string> CLI_GUI::vaultListScan(const std::string& vaultPath) {
    namespace fs = std::filesystem;

    if (fs::is_directory(vaultPath))
    {
        std::vector<std::string> file_names;

        for (const auto& entry : fs::recursive_directory_iterator(vaultPath))
        {
            if (entry.is_regular_file())
            file_names.push_back(entry.path().stem().string());
        }

        return file_names;
    } else return {};
}

void CLI_GUI::printAllTasks() {
    if (!vaultList.empty()) {
        std::cout << "Your tasks: \n";
        for (int i = 0; i < vaultList.size(); i++) {
            std::cout << vaultList[i] << "\n";
        }
    } else {
        std::cout << ">> Tasks not find!\n";
    }

}

void CLI_GUI::helpMenu() {
    std::cout << "===========================================================================================\n";
    std::cout << "Usage: todo [option]\n";
    std::cout << "  -h, --help                                           Show help menu\n";
    std::cout << "  -v, --version                                        Show program version\n";
    std::cout << "\n";
    std::cout << "  -s, --show (optional:[task])                         Show your tasks\n";
    std::cout << "  -d, --delete [task]                                  Delete your task\n";
    std::cout << "  -c, --create [task]                                  Create new task\n";
    std::cout << "  --ch-desc, --description [task] [description]        Change description in task\n";
    std::cout << "  --ch-stat, --status [task]                           Change status of task\n";
    std::cout << "==========================================================================================\n";
}

void CLI_GUI::versionMenu() {
    std::cout << ">> Program version v0.0.8\n";
}