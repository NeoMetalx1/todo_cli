#include "../../include/Json/Json.h"

void Json::editDiscription(const std::string& description) {
    std::string path = rootPath + jsonName + ".json";
    std::ifstream readFile(path); // make reader
    nlohmann::json existingJson;

    if (readFile.is_open()) {  // write all data that reader read in json
        readFile >> existingJson;
        readFile.close();
    }

    existingJson["Description"] = description;

    std::ofstream jsonVault(path);
    jsonVault << std::setw(4) << existingJson;
    jsonVault.close();
}

void Json::editStatus(const bool& status) {
    std::string path = rootPath + jsonName + ".json";
    std::ifstream readFile(path);
    nlohmann::json existingJson;

    if (readFile.is_open()) {
        readFile >> existingJson;
        readFile.close();
    }

    existingJson["Status"] = status;

    std::ofstream jsonVault(path);
    jsonVault << std::setw(4) << existingJson;
    jsonVault.close();
}

void Json::deleteVault(const std::string& userJsonName) {
    namespace fs = std::filesystem;

    jsonName = userJsonName;
    std::string path = rootPath + jsonName + ".json";

    if (fs::exists(path)) {
        if (fs::remove(path)) {
            std::cout << "Task deleted: " << path << '\n';
        } else {
            std::cerr << "Error while trying to delete task: " << path << '\n';
        }
    } else {
        std::cerr << "Task not found: " << path << '\n';
    }

}

void Json::dataGet(const std::string& vaultName) {
    std::string vault = rootPath + vaultName + ".json";
    std::ifstream vaultFile(vault);

    if (!vaultFile.is_open()) {
        std::cout << "Could not open input file\n";
    }

    std::vector<std::string> vaultLines;
    std::string vaultLine;

    while(std::getline(vaultFile, vaultLine)) {
        vaultLines.push_back(vaultLine);
    }

    for ( unsigned int i = 0; i < vaultLines.size(); i++ ) {
        std::cout << (i+1) << ": " << vaultLines[i] << "\n"; 
    }    

}