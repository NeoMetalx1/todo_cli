#include "include/Json/Json.h"
#include "include/Cli/Cli.h"

int main(int argc, char* argv[]) {
    CLI_GUI interface;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            interface.helpMenu();
            return 0;
        } else if (arg == "-v" || arg == "--version") {
            interface.versionMenu();
            return 0;
        } else if (arg == "-s" || arg == "--show") {
            interface.printTasks();
            return 0;
        } else if (arg == "-d" || arg == "--delete") {
            std::string path = argv[++i];
            Json taskConfigurer(path);
            taskConfigurer.deleteVault(path);
            return 0;
        } else if (arg == "-c" || arg == "--create") {
            std::string path = argv[++i];
            Json taskCreate(path);
            return 0;
        } else if (arg == "--change-desc" || arg == "--description") {
            std::string path = argv[++i];
            Json changeDescription(path);
            std::string description = argv[++i];
            changeDescription.editDiscription(description);
            return 0;
        } else {
            std::cout << "Unknown argument: " << arg << "\n";
        }

        
    }


    return 0;
}