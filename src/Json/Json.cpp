#include "../../include/Json/Json.h"

void Json::createJsonVault(const std::string& userJsonName) {
    jsonName = userJsonName;
    std::string path = vaultPath + jsonName + ".json";

    if (std::filesystem::exists(vaultPath)) {
        std::ofstream jsonVault(path);
        nlohmann::json jsonNew;
        jsonNew["Name"] = jsonName;
        jsonNew["Description"] = "";
        jsonNew["Status"] = false;
        jsonVault << std::setw(4) << jsonNew;
        jsonVault.close();
        std::cout << "Task created!\n";
    } else {
        std::cout << ">> Cant find vault folder!\n";
    }
}

void Json::editDiscription(const std::string& userJsonName, const std::string& description) {
    jsonName = userJsonName;
    std::string path = vaultPath + jsonName + ".json";
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
    std::string path = vaultPath + jsonName + ".json";
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
    std::string path = vaultPath + jsonName + ".json";

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

void Json::printTaskData(const std::string& vaultName) {
    std::string vault = vaultPath + vaultName + ".json";
    std::ifstream vaultFile(vault);

    if (!vaultFile.is_open()) {
        std::cout << "Could not open input file\n";
    }

    nlohmann::json vaultEditor;
    vaultFile >> vaultEditor;

    std::string name = vaultEditor["Name"];
    std::string description = vaultEditor["Description"];
    bool status = vaultEditor["Status"];

    std::cout << "==========================================================================================\n";
    std::cout << "\tName: " << name << "\n";
    std::cout << "\tDescription: " << description << "\n";
    std::cout << "\tStatus: " << status << "\n";
    std::cout << "==========================================================================================\n";
}