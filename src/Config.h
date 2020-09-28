#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> ConfigData;

class Config
{
public:
	static Config& get()
	{
		static Config config;
		return config;
	}

	Config();
	Config* getConfig();
	void loadConfigFromFile(const std::string& file);
	static bool saveConfig(const ConfigData& data, std::string& file);
	int getHeight() const;
	int getWidth() const;
	float getRenderDistance() const;
	bool getFullscreen() const;
	float getFieldOfView() const;
	float getVerticalSensitivity() const;
	float getHorizontalSensitivity() const;
	void printConfig() const;


private:
	ConfigData allSettings;
	bool fullscreen;
	int windowWidth;
	int windowHeight;
	float fieldOfView;
	float renderDistance;
	float verticalSensitivity;
	float horizontalSensitivity;
};
#endif