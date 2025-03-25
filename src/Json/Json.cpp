#include "../../include/Json/Json.h"

void Json::editDiscription(std::string description) {
    std::string path = "vault/" + jsonName + ".json";
    std::ifstream inputFile(path); // make reader
    nlohmann::json existingJson;

    if (inputFile.is_open()) {  // write all data that reader read in json
        inputFile >> existingJson;
        inputFile.close();
    }

    existingJson["Description"] = description;

    std::ofstream jsonVault(path);
    jsonVault << std::setw(4) << existingJson;
    jsonVault.close();
}