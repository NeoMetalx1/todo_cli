#include "Json.h"
#include <iostream>
#include <fstream>

void JsonVault::jsonCreation(std::string vaultName) {

    path = "vaults/" + vaultName;
    std::ofstream Vault(path);

    if (!Vault.is_open()) {
        std::cout << "Failed to open JSON vault.";   
    } else {
        jsonNew["Name"] = vaultName;
        jsonNew["Descripton"] = "Default";
        jsonNew["Task_Status"] = true;

        Vault << std::setw(4) << jsonNew;
    }
    Vault.close();
}
