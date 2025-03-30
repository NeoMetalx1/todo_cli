#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

class Json {
private:
    std::string jsonName;
public:
    Json(const std::string& userJsonName) {
        jsonName = userJsonName;
        std::string path = "vault/" + jsonName + ".json";

        if (!std::filesystem::exists(path)) {
            std::ofstream jsonVault(path);
            nlohmann::json jsonNew;
            jsonNew["Name"] = jsonName;
            jsonNew["Description"] = "";
            jsonNew["Status"] = false;
            jsonVault << std::setw(4) << jsonNew;
            jsonVault.close();
        }
    }

    void editDiscription(const std::string& description);
    void editStatus(const bool& status);
};