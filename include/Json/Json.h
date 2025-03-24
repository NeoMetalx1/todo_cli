#pragma once

#include <iostream>
#include <fstream>
#include "nlohmann\json.hpp"

class Json {
private:
    nlohmann::json jsonNew;
public:
    Json(std::string jsonName) {
        std::string path = "vault/" + jsonName;
        std::ofstream jsonVault(path);

        if (!jsonVault.is_open()) {
            std::cout << "Failed to open Json vault";
        } else {
            jsonNew["Name"] = jsonName;
            jsonNew["Description"] = "Default";
            jsonNew["Task_Status"] = true;

            jsonVault << std::setw(4) << jsonNew;
        }
        jsonVault.close();
    }
};