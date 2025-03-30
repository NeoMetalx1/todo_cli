#include "include/Json/Json.h"
#include "include/Cli/Cli.h"

int main() {
    std::string userDescription = "task";
    bool user = false;

    Json jsonVault("Task 2"); // create json file with name in quotes
    jsonVault.editDiscription(userDescription);
    jsonVault.editStatus(user);

    CLI_GUI interface;
}