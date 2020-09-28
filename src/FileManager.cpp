#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>


#include "FileManager.h"

ConfigData readFromConfig(const std::string& file)
{
	ConfigData data;
	std::stringstream stream(file);
	std::string entry;
	while (stream >> entry)
	{
		std::string next;
		stream >> next;
		data.emplace(entry, next);
	}
	return data;
}

std::string loadConfig(const std::string& file)
{
	std::ifstream ifs(file);
	std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	std::cout << content << std::endl;
	return content;
}

bool writeToConfig(const ConfigData& settings, const std::string& file)
{
	std::ofstream stream(file);
	for (const auto& setting : settings)
	{
		stream << setting.first << " " << setting.second << std::endl;
	}
	stream.close();
	return true;
}

std::string getFileContents(const std::string &filePath)
{
	std::ifstream inFile(filePath);
	if (!inFile.is_open()) {
		throw std::runtime_error("Unable to open file: " + filePath);
	}

	std::stringstream stream;

	stream << inFile.rdbuf();
	return stream.str();
}
