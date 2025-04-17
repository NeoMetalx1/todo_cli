#include "include/Json/Json.h"
#include "include/Cli/UI.h"
#include "include/Cli/Flags.h"
#include "include/Cli/Cli.h"
#include <chrono>

int main(int argc, char* argv[]) {
    //auto start = std::chrono::high_resolution_clock::now();

    UI UIElements;
    CLI_GUI CliInterface;
    cliArguments arguments;
    int userOption;

    if (argc == 1) {
        do {
            UIElements.printLogo();
            UIElements.cliMainMenu();
            std::cout << "\n Enter Option: ";
            std::cin >> userOption;
            CliInterface.optionHandler(userOption);
        }  while (userOption != 9);
    } else {
        arguments.argumentHandler(argc, argv);
    }


    /*auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds\n";
    */
    return 0;
}