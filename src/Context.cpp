#include "Context.h"

#include <iostream>


#include "glad/glad.h"

unsigned int g_X;
unsigned int g_Y;

Context::Context(const Config &config)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    // settings.attributeFlags = sf::ContextSettings::Core;
    // This is no longer necessary due to the Mac Support update.

    if (config.getFullscreen()) {
        window.create(sf::VideoMode::getDesktopMode(), "Voxel Project",
                      sf::Style::Fullscreen, settings);
    }
    else {
        sf::VideoMode winMode(config.getWidth(), config.getHeight());
        window.create(winMode, "Voxel Project", sf::Style::Close, settings);
    }

    if (!gladLoadGL()) {

        exit(-1);
    }

    glViewport(0, 0, window.getSize().x, window.getSize().y);

    glCullFace(GL_BACK);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
