//
// Created by Ray_1024 on 22.06.2025.
//

#ifndef WINDOWSYSTEM_HPP
#define WINDOWSYSTEM_HPP

#include "engine/application/ApplicationConfiguration.hpp"
#include "engine/ecs/System.hpp"

#include <SFML/Graphics.hpp>

namespace endora::ecs {
    class WindowSystem final : public endora::ecs::System {
    public:
        explicit WindowSystem(const std::shared_ptr<utils::Context> &context)
            : System(context) {
            const auto applicationConfiguration = context->resolve<endora::ApplicationConfiguration>();

            const auto window = std::make_shared<sf::RenderWindow>();
            if (applicationConfiguration->getFullscreen())
                window->create(sf::VideoMode::getDesktopMode(), applicationConfiguration->getTitle().data(),
                               sf::Style::Fullscreen);
            else
                window->create(sf::VideoMode({
                                   applicationConfiguration->getWidth(),
                                   applicationConfiguration->getHeight()
                               }),
                               applicationConfiguration->getTitle().data());
            if (applicationConfiguration->getVSync())
                window->setVerticalSyncEnabled(true);
            else
                window->setFramerateLimit(applicationConfiguration->getFps());
            context->registerSingleton(window);
        }

        void postConstruct() override {
        }
        void preDestruct() override {
        }

        void update() override {
        }

        ~WindowSystem() override = default;
    };
} // endora

#endif //WINDOWSYSTEM_HPP
