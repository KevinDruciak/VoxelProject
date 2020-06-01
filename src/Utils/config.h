#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> ConfigData;

class Config {
public:
    static Config& get() {
        static Config config;
        return config;
    }
    Config();
    Config* getConfig();
    void loadConfigFromFile(const std::string& file);
    bool saveConfig(ConfigData data, std::string& file);
    int getHeight();
    int getWidth();
    
private:
    ConfigData allSettings;
    int getWindowHeight();
    int getWindowWidth();
    bool fullscreen;
    int windowWidth;
    int windowHeight;
    int fieldOfView;
    float renderDistance;
    float verticalSensitivity;
    float horizontalSensitivity;
};
#endif
