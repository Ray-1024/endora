//
// Created by Ray_1024 on 22.06.2025.
//

#ifndef GRAPHICSSYSTEM_HPP
#define GRAPHICSSYSTEM_HPP
#include <SFML/Graphics.hpp>

#include "engine/ecs/System.hpp"
#include "sprite/batch/SpriteBatch.hpp"

namespace endora::ecs {
    class GraphicsSystem final : public endora::ecs::System {
        std::shared_ptr<sf::RenderWindow> window;
        endora::SpriteBatch spriteBatch{nullptr, 8192};
        sf::Texture texture;

    public:
        explicit GraphicsSystem(const std::shared_ptr<endora::utils::Context> &context)
            : System(context) {
            texture.loadFromFile("./assets/images/tiles.jpg");
            srand(time(0));
        }

        void postConstruct() override {
            window = context->resolve<sf::RenderWindow>();
            spriteBatch.setRenderTarget(window.get());
        }

        void preDestruct() override {
        }

        void update() override {
            sf::RectangleShape rect({16.0f, 16.0f});
            rect.setTexture(&texture);

            if (window->isOpen()) {
                window->clear();
                for (uint32_t x = 0; x < window->getSize().x; x += 16) {
                    for (uint32_t y = 0; y < window->getSize().y; y += 16) {
                        rect.setPosition({static_cast<float>(x), static_cast<float>(y)});
                        rect.setTextureRect(sf::IntRect{
                            {
                                static_cast<int>(rand() % (texture.getSize().x - 16)),
                                static_cast<int>(rand() % (texture.getSize().y - 16))
                            },
                            {16, 16}
                        });
                        spriteBatch.draw(rect);
                    }
                }
                spriteBatch.draw(rect);
                spriteBatch.flush();
                window->display();
            }
        }

        ~GraphicsSystem() override = default;
    };
} // endora

#endif //GRAPHICSSYSTEM_HPP
