#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

class Json {
private:
    std::string jsonName;
    std::string vaultPath = "vault/";
public:
    void createJsonVault(const std::string& userJsonName);
    void editDiscription(const std::string& userJsonName, const std::string& description);
    void editStatus(const bool& status);
    void deleteVault(const std::string& userJsonName);
    void printTaskData(const std::string& vaultName);
};