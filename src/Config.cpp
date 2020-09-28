#include <string>
#include "Config.h"
#include <iostream>
#include "FileManager.h"

Config::Config() :
	fullscreen(false),
	windowWidth(1280),
	windowHeight(720),
	fieldOfView(65.f),
	renderDistance(50.f),
	verticalSensitivity(1.f),
	horizontalSensitivity(1.f)
{
}

Config* Config::getConfig()
{
	return this;
}

bool Config::saveConfig(const ConfigData& data, std::string& file)
{
	return writeToConfig(data, file) ? true : false;
}

void Config::loadConfigFromFile(const std::string& file)
{
	auto settings = readFromConfig(loadConfig(file));
	allSettings = settings;
	std::cout << "got here" << std::endl;

	fullscreen = std::stoi(settings["fullscreen"]);
	windowWidth = std::stoi(settings["windowWidth"]);
	windowHeight = std::stoi(settings["windowHeight"]);
	fieldOfView = std::stof(settings["fieldOfView"]);
	renderDistance = std::stof(settings["renderDistance"]);
	verticalSensitivity = std::stof(settings["verticalSensitivity"]);
	horizontalSensitivity = std::stof(settings["horizontalSensitivity"]);
	std::cout << "got here2" << std::endl;

}

int Config::getHeight() const
{
	return windowHeight;
}

int Config::getWidth() const
{
	return windowWidth;
}

float Config::getRenderDistance() const
{
	return renderDistance;
}

bool Config::getFullscreen() const
{
	return fullscreen;
}

float Config::getFieldOfView() const
{
	return fieldOfView;
}

float Config::getVerticalSensitivity() const
{
	return verticalSensitivity;
}

float Config::getHorizontalSensitivity() const
{
	return horizontalSensitivity;
}

void Config::printConfig() const
{
	std::cout << "fullscreen " << fullscreen << std::endl;
	std::cout << "windowWidth " << windowWidth << std::endl;
	std::cout << "windowHeight " << windowHeight << std::endl;
	std::cout << "fieldOfView " << fieldOfView << std::endl;
	std::cout << "renderDistance " << renderDistance << std::endl;
	std::cout << "verticalSensitivity " << verticalSensitivity << std::endl;
	std::cout << "horizontalSensitivity " << horizontalSensitivity << std::endl;
}
