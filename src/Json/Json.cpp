#include "../../include/Json/Json.h"

void Json::editDiscription(const std::string& description) {
    std::string path = "vault/" + jsonName + ".json";
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
    std::string path = "vault/" + jsonName + ".json";
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
    std::string path = "vault/" + jsonName + ".json";

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