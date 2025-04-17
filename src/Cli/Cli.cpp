#include "../../include/Cli/Cli.h"
UI interface;
Json vaultManage;

void CLI_GUI::optionHandler(int option) {
    std::string vaultName;
    switch (option) {
        case 1: 
        {
            interface.clearScreen();
            interface.printAllTasks();
            interface.waitForEnter();
            break;
        }
        case 2: 
        {
            interface.clearScreen();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter name of new task: ";
            std::getline(std::cin, vaultName);
            vaultManage.createJsonVault(vaultName);
            break;    
        }
        case 3:
        {
            interface.clearScreen();
            interface.printAllTasks();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter name of task that you want to delete: ";
            std::getline(std::cin, vaultName);
            vaultManage.deleteVault(vaultName);
            break;
        }
        case 4:
        {
            interface.clearScreen();
            interface.printAllTasks();
            std::string newDescription;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter name of task to change description: ";
            std::getline(std::cin, vaultName);
            std::cout << "\n";
            std::cout << "Enter new description: ";
            std::getline(std::cin, newDescription);
            vaultManage.editDiscription(vaultName, newDescription);
            break;
        }
        case 5:
        {
            interface.clearScreen();
            interface.printAllTasks();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter name of task to change status: ";
            std::getline(std::cin, vaultName);
            vaultManage.editStatus(vaultName);
            break;
        }
        case 8:
        {
            interface.clearScreen();
            interface.versionMenu();
            interface.waitForEnter();
            break;
        }
        case 9:
        {
            break;
        }
        default:
        {
            interface.clearScreen();
            std::cout << "Invalid option!\n";
            break;
        }
    }
}