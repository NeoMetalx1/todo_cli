all:
	g++ -std=c++17 main.cpp src/Json/Json.cpp src/Cli/UI.cpp src/Cli/Flags.cpp src/Cli/Cli.cpp -o todo