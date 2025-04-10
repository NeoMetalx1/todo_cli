#include "../../include/Cli/Flags.h"

int cliArguments::argumentHandler(int argc, char* argv[]) {
    Json vaultManage;
    CLI_GUI interface;
    std::string vaultName;
    std::string* vaultName_ptr = &vaultName;

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
            if (argc == 3) {
                *vaultName_ptr = argv[++i];
                vaultManage.printTaskData(vaultName);
            } else interface.printAllTasks();
            return 0;
        } else if (arg == "-d" || arg == "--delete") {
            *vaultName_ptr = argv[++i];
            vaultManage.deleteVault(vaultName);
            return 0;
        } else if (arg == "-c" || arg == "--create") {
            *vaultName_ptr = argv[++i];
            vaultManage.createJsonVault(vaultName);
            return 0;
        } else if (arg == "--ch-desc" || arg == "--description") {
            *vaultName_ptr = argv[++i];
            std::string description = argv[++i];
            vaultManage.editDiscription(vaultName, description);
            return 0;
        } else if (arg == "--ch-stat" || arg == "--status") {
            *vaultName_ptr = argv[++i];
            vaultManage.editStatus(vaultName);
            return 0;
        } else {
            std::cout << "Unknown argument: " << arg << "\n";
            return 0;
        }
    }
    return 0;
}