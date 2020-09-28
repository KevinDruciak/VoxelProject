#include "Application.h"
#include "States/PlayingState.h"
#include "World/Block/BlockDatabase.h"
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;
constexpr std::chrono::nanoseconds timestep(1ms);

Application::Application(const Config &config)
    : m_context(config)
    , m_camera(config)
    , m_config(config)
{
	std::cout << "got here" << std::endl;
    BlockDatabase::get();
    pushState<StatePlaying>(*this, config);
}

float g_timeElapsed = 0;

void Application::run()
{
	using clock = std::chrono::high_resolution_clock;
	std::chrono::nanoseconds lag(0ns);
	auto time_start = clock::now();
	auto timer = clock::now();
	int frames = 0;
	while (m_context.window.isOpen() && !m_states.empty()) {
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		frames++;
		if (clock::now() - timer > std::chrono::duration<long, std::nano>(1000000000)) {
			timer += std::chrono::duration<long, std::nano>(1000000000);
			std::cout << "FPS: " << frames << std::endl;
			frames = 0;
		}

		float dt = std::chrono::duration<float>(delta_time).count();
		auto &state = *m_states.back();
		state.handleInput();
		state.update(dt);
		m_camera.update();
		state.render(m_masterRenderer);
		m_masterRenderer.finishRender(m_context.window, m_camera);
		handleEvents();
		if (m_isPopState) {
			m_isPopState = false;
			m_states.pop_back();
		}
		g_timeElapsed += dt;
	}

}

void Application::handleEvents()
{
    sf::Event e;
    while (m_context.window.pollEvent(e)) {
        m_states.back()->handleEvent(e);
        switch (e.type) {
            case sf::Event::Closed:
                m_context.window.close();
                break;

            case sf::Event::KeyPressed:
                switch (e.key.code) {
                    case sf::Keyboard::Escape:
                        m_context.window.close();
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void Application::popState()
{
    m_isPopState = true;
}

void Application::turnOffMouse()
{
    m_context.window.setMouseCursorVisible(false);
}

void Application::turnOnMouse()
{
    m_context.window.setMouseCursorVisible(true);
}

Camera &Application::getCamera()
{
	return m_camera;
}

const sf::Window &Application::getWindow() const
{
	return m_context.window;
}
