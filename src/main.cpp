#include "Engine/Application.h"

#include <fstream>
#include <iostream>

#include "Config.h"

#ifdef __WIN32
extern "C" {
// Enable dedicated graphics
__declspec(dllexport) bool NvOptimusEnablement = true;
__declspec(dllexport) bool AmdPowerXpressRequestHighPerformance = true;
}
#endif // __WIN32

int main()
{
	Config config;
	config.loadConfigFromFile("C:/Users/bakad/Desktop/VoxelProject/VoxelProject/VoxelProject/config.txt");
	config.printConfig();
	Application app(config);
	app.run();
}
