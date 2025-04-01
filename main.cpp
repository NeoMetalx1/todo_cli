#include "include/Json/Json.h"
#include "include/Cli/Cli.h"
#include "include/Cli/Flags.h"

int main(int argc, char* argv[]) {
    cliArguments arguments;

    arguments.argumentHandler(argc, argv);

    return 0;
}