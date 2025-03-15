#pragma once

#include "nlohmann/json.hpp"
#include <iostream>

class JsonVault{
private:
    std::string path;
    nlohmann::json jsonNew;
public:

    JsonVault(std::string JsonName) {}

    void jsonCreation(std::string vaultName);
};
