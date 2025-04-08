#include "../../include/Cli/Flags.h"

int cliArguments::argumentHandler(int argc, char* argv[]) {
    CLI_GUI interface;
    if (argc == 1) {
        interface.helpMenu();
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            interface.helpMenu();
            return 0;
        } else if (arg == "-v" || arg == "--version") {
            interface.versionMenu();
            return 0;
        } else if (arg == "-s" || arg == "--show") {
            interface.printAllTasks();
            return 0;
        } else if (arg == "-d" || arg == "--delete") {
            std::string path = argv[++i];
            Json taskConfigurer(path);
            taskConfigurer.deleteVault(path);
            return 0;
        } else if (arg == "-c" || arg == "--create") {
            std::string jsonName = argv[++i];
            Json taskCreate(jsonName);
            return 0;
        } else if (arg == "--change-desc" || arg == "--description") {
            std::string path = argv[++i];
            Json changeDescription(path);
            std::string description = argv[++i];
            changeDescription.editDiscription(description);
            return 0;
        } else {
            std::cout << "Unknown argument: " << arg << "\n";
            return 0;
        }
    }
    return 0;
}