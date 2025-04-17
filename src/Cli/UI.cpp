#include "../../include/Cli/UI.h"

UI::UI() {
    vaultList = vaultListScan(vaultPath);
}

std::vector<std::string> UI::vaultListScan(const std::string& vaultPath) {
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

void UI::printAllTasks() {
    if (!vaultList.empty()) {
        std::cout << "Your tasks: \n";
        for (int i = 0; i < vaultList.size(); i++) {
            std::cout << vaultList[i] << "\n";
        }
    } else {
        std::cout << ">> Tasks not find!\n";
    }

}

void UI::waitForEnter() {
    std::cout << "Press enter" << "\n";
#ifdef _WIN32
    while(true) {
        char key = _getch();
        if (key == 13) break;
    }
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char ch = getchar();

    while (ch != '\n') {
        ch = getchar();
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
}

void UI::clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void UI::helpMenu() {
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

void UI::versionMenu() {
    std::cout << ">> Program version: " << VERSION << "\n";
}

void UI::cliMainMenu() {
    std::cout << "+-----------------------------------------------------------------------+" << "\n";
    std::cout << "|             Options             |             Description             |" << "\n";
    std::cout << "+---------------------------------+-------------------------------------+" << "\n";
    std::cout << "| 1. Show all tasks               |                                     |" << "\n";
    std::cout << "| 2. Add task                     |                                     |" << "\n";
    std::cout << "| 3. Delete task                  |                                     |" << "\n";
    std::cout << "| 4. Change task description      +-------------------------------------+" << "\n";
    std::cout << "| 5. Change task status           |               Credits               |" << "\n";
    std::cout << "|                                 +-------------------------------------|" << "\n";
    std::cout << "| 8. Show version                 | github:@NeoMetalx1                  |" << "\n";
    std::cout << "| 9. Exit                         |                                     |" << "\n";
    std::cout << "+-----------------------------------------------------------------------+" << "\n";
}

void UI::printLogo() {
    std::cout << R"(  _____         _         _     _     _   
 |_   _|__   __| | ___   | |   (_)___| |_ 
   | |/ _ \ / _` |/ _ \  | |   | / __| __|
   | | (_) | (_| | (_) | | |___| \__ \ |_ 
   |_|\___/ \__,_|\___/  |_____|_|___/\__|
                                          )" << "\n";
}