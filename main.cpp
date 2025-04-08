#include "include/Json/Json.h"
#include "include/Cli/Cli.h"
#include "include/Cli/Flags.h"
#include <chrono>

int main(int argc, char* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();

    cliArguments arguments;

    arguments.argumentHandler(argc, argv);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds\n";

    return 0;
}