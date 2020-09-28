#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, std::string> ConfigData;

std::string loadConfig(const std::string& file);
ConfigData readFromConfig(const std::string& file);
bool writeToConfig(const ConfigData& settings, const std::string& file);
std::string getFileContents(const std::string &filePath);

#endif
