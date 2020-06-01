#include <string>

#include "config.h"
#include "file_manager.h"


Config::Config() : fullscreen(false), windowWidth(1280), windowHeight(720), fieldOfView(65.f), renderDistance(50.f), verticalSensitivity(1.f), horizontalSensitivity(1.f) {}

Config* Config::getConfig() {
    return this;
}

bool Config::saveConfig(ConfigData data, std::string& file) {
    return writeToConfig(data, file) ? true : false;
}

void Config::loadConfigFromFile(const std::string& file) {
    auto settings = readFromConfig(loadConfig(file));
    allSettings = settings;
    fullscreen = std::stoi(settings["fullscreen"]);
    windowWidth = std::stoi(settings["windowWidth"]);
    windowHeight = std::stoi(settings["windowHeight"]);
    fieldOfView = std::stof(settings["fieldOfView"]);
    renderDistance = std::stof(settings["renderDistance"]);
    verticalSensitivity = std::stof(settings["verticalSensitivity"]);
    horizontalSensitivity = std::stof(settings["horizontalSensitivity"]);
}

int Config::getHeight() {
    return windowHeight;
}
int Config::getWidth() {
    return windowWidth;
}


