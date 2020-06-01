#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

#include "file_manager.h"

ConfigData readFromConfig(const std::string& file) {
    ConfigData data;
    std::stringstream stream(file);
    std::string entry;
    while (stream >> entry) {
        std::string next;
        stream >> next;
        data.emplace(entry, next);
    }
    return data;
}

std::string loadConfig(const std::string& file) {
    std::ifstream ifs(file);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    std::cout << content << std::endl;
    return content;
}

bool writeToConfig(ConfigData settings, const std::string& file) {
    std::ofstream stream(file);
    for (auto& setting : settings) {
        stream << setting.first << " " << setting.second << std::endl;
    }
    stream.close();
    return true;
}

std::string loadConfig(const std::string& file);
ConfigData readFromConfig(const std::string& file);
bool writeToConfig(const std::string& file);
