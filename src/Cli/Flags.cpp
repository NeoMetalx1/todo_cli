#include "../../include/Cli/Flags.h"

int cliArguments::argumentHandler(int argc, char* argv[]) {
    Json vaultManage;
    UI interface;
    std::string vaultName;

    if (argc == 1) {
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
            if (argc == 3) {
                vaultName = argv[++i];
                vaultManage.printTaskData(vaultName);
            } else interface.printAllTasks();
            return 0;
        } else if (arg == "-d" || arg == "--delete") {
            vaultName = argv[++i];
            vaultManage.deleteVault(vaultName);
            return 0;
        } else if (arg == "-c" || arg == "--create") {
            vaultName = argv[++i];
            vaultManage.createJsonVault(vaultName);
            return 0;
        } else if (arg == "--ch-desc" || arg == "--description") {
            vaultName = argv[++i];
            std::string description = argv[++i];
            vaultManage.editDiscription(vaultName, description);
            return 0;
        } else if (arg == "--ch-stat" || arg == "--status") {
            vaultName = argv[++i];
            vaultManage.editStatus(vaultName);
            return 0;
        } else {
            std::cout << "Unknown argument: " << arg << "\n";
            return 0;
        }
    }
    return 0;
}