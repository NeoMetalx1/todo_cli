#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

class Json {
private:
    std::string jsonName;
    std::string rootPath = "vault/";
public:
    Json(const std::string& userJsonName) {
        jsonName = userJsonName;
        std::string path = "vault/" + jsonName + ".json";

        if (std::filesystem::exists(rootPath)) {
            std::ofstream jsonVault(path);
            nlohmann::json jsonNew;
            jsonNew["Name"] = jsonName;
            jsonNew["Description"] = "";
            jsonNew["Status"] = false;
            jsonVault << std::setw(4) << jsonNew;
            jsonVault.close();
            std::cout << "Task created!\n";
        } else {
            std::cout << "Cant find vault folder!\n";
        }
    }

    void editDiscription(const std::string& description);
    void editStatus(const bool& status);
    void deleteVault(const std::string& userJsonName);
};