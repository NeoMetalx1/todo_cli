#include "../../include/Cli/Cli.h"

CLI_GUI::CLI_GUI() {
    std::cout << "Scanning your task\n";
    vaultList = vaultListScan(vaultPath);
    for (int i = 0; i < vaultList.size(); i++) {
        std::cout << vaultList[i] << std::endl;
    }
}

std::vector<std::string> CLI_GUI::vaultListScan(const std::string& vaultPath) {

    namespace fs = std::filesystem;

    if (fs::is_directory(vaultPath))
    {
        std::vector<std::string> file_names;

        for (const auto& entry : fs::recursive_directory_iterator(vaultPath))
        {
            if (entry.is_regular_file())
            file_names.push_back(entry.path().filename().string());
        }

        return file_names;
    } else return {};
}