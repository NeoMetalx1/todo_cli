/* code by :
 _   _           ___  ___     _        _ 
| \ | |          |  \/  |    | |      | |
|  \| | ___  ___ | .  . | ___| |_ __ _| |      github: https://github.com/NeoMetalx1
| . ` |/ _ \/ _ \| |\/| |/ _ \ __/ _` | |      rep: todo_cli
| |\  |  __/ (_) | |  | |  __/ || (_| | |      
\_| \_/\___|\___/\_|  |_/\___|\__\__,_|_|
       78 101 111 77 101 116 97 108                    */

#include "include/Json/Json.h"
#include "include/Cli/UI.h"
#include "include/Cli/Flags.h"
#include "include/Cli/Cli.h"
#include <chrono>

int main(int argc, char* argv[]) {
    UI UIElements;
    CLI_GUI CliInterface;
    cliArguments arguments;
    int userOption;

    if (argc == 1) {
        do {
            UIElements.clearScreen();
            UIElements.printLogo();
            UIElements.cliMainMenu();
            std::cout << "\nEnter Option: ";
            std::cin >> userOption;
            CliInterface.optionHandler(userOption);
        }  while (userOption != 9);
    } else {
        arguments.argumentHandler(argc, argv);
    }
    return 0;
}
