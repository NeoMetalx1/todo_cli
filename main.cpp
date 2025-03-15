#include "List.h"
#include "Json.h"
#include <vector>
#include <time.h>

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

int main() {
    int option;
    std::string newListName;
    List obj(""); 
    JsonVault jsonObj(""); 

    do {
        std::cout << "1. My tasks" << std::endl;
        std::cout << "2. Create new task" << std::endl;
        std::cout << "3. Exit" << std::endl;
        do {
            std::cout << "Choose option: ";
            std::cin >> option;
        } while (option < 1 || option > 3);

        switch(option) {
            case 1: {
                obj.printAllLists();
                break;
            }
            case 2: {
                std::cout << "Enter new task title: ";
                std::cin.ignore();
                std::getline(std::cin, newListName);

                if (newListName.empty()) {
                    std::cout << "Error name cant be empty!" << std::endl;
                    return 1; 
                }

                obj = List(newListName);
                jsonObj = JsonVault(newListName);
                jsonObj.jsonCreation(newListName);

                std::cout << std::endl << "Task created" << "\n\n";
                break;
            }
            case 3:
                break;
        }

    } while (option != 3);

    return 0;
}