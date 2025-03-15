#include "List.h"
#include "Json.h"
#include "MenuCLI.h"
#include <cstdlib>
#include <vector>
#include <time.h>
#include <conio.h>

int main() {
    List obj("");
    JsonVault jsonObj(""); 
    int option;
    int mainMenuOption;
    std::string newListName;

    do {
        clearScreen();
        MainMenu(option);
        do {
            std::cout << "Choose option: ";
            std::cin >> option;
        } while (option < 1 || option > 4);

        switch (option) {
            case 1:
                clearScreen();
                ListTaskMenu(); 
                obj.printAllLists();

                std::cout << "1. Delete task" << std::endl;
                std::cout << "Choose option: ";
                std::cin >> mainMenuOption;

                switch (mainMenuOption) {
                    case 1:
                        clearScreen();
                        obj.printAllLists();

                        std::string vaultName;

                        std::cout << "Write vault name (to cancel type 'exit'): ";
                        std::cin.ignore();
                        std::getline(std::cin, vaultName);

                        if (vaultName == "exit") {
                            break;
                        }

                        obj.vaultDelete(vaultName);
                        std::cout << "Press (enter) to countinue ";
                        while (true) {
                            char key = _getch();
                            if (key == 13) break;
                        }
                        break;
                }
                break;

            case 2:
                clearScreen();
                std::cout << "Enter new task title (to cancel type 'exit'): ";
                std::cin.ignore();
                std::getline(std::cin, newListName);

                if (newListName.empty()) {
                    std::cout << "Error name cant be empty!" << std::endl;
                    return 1; 
                }
                if (newListName == "exit") {
                    break;
                }

                obj = List(newListName);
                jsonObj = JsonVault(newListName);
                jsonObj.jsonCreation(newListName);

                std::cout << std::endl << "Task created" << "\n\n";
                break;

            case 3:
                InfoMenu();
                while (true) {
                    char key = _getch();
                    if (key == 13) break;
                }
                break;
            case 4:
                break;
        }

    } while (option != 4);
}

