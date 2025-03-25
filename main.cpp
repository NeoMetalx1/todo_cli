#include "include\Json\Json.h"

int main() {
    std::string userDescription;

    Json jsonVault("Task 2"); // create json file with name in quotes
    jsonVault.editDiscription(userDescription);
}