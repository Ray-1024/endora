//
// Created by Ray_1024 on 22.06.2025.
//

#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP
#include <SFML/Graphics/RenderWindow.hpp>

#include "engine/ecs/System.hpp"
#include <SFML/Graphics.hpp>

#include "engine/application/Application.hpp"
#include "engine/ecs/window/WindowSystem.hpp"

namespace endora::ecs {
    class InputSystem final : public endora::ecs::System {
        std::shared_ptr<endora::Application> application;
        std::shared_ptr<sf::RenderWindow> window;
        sf::Event event{};

    public:
        explicit InputSystem(const std::shared_ptr<endora::utils::Context> &context)
            : System(context) {
        }

        void postConstruct() override {
            application = context->resolve<endora::Application>();
            window = context->resolve<sf::RenderWindow>();
        }

        void update() override {
            if (window->isOpen()) {
                while (window->pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window->close();
                        application->stop();
                    } else if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Key::Escape) {
                            window->close();
                            application->stop();
                        }
                    }
                }
            }
        }

        void preDestruct() override {}

        ~InputSystem() override = default;
    };
} // endora

#endif //INPUTSYSTEM_HPP
