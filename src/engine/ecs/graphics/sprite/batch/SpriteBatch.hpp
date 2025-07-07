//
// Created by ray1024 on 27.06.2025.
//

#ifndef SPRITEBATCH_HPP
#define SPRITEBATCH_HPP

#include<SFML/Graphics.hpp>

#include "engine/utils/codegeneration/GetterSetter.hpp"

namespace endora {
    class SpriteBatch {
        GETSET_FIELD(sf::RenderStates, renderStates, RenderStates)
        sf::RenderTarget *renderTarget{nullptr};
        GETTER(sf::RenderTarget*, renderTarget, RenderTarget)
        sf::Vertex *vertices{nullptr};
        uint32_t index{};
        uint32_t vertexCount{};

    public:
        explicit SpriteBatch(sf::RenderTarget *renderTarget = nullptr, const uint32_t spritesCount = 1024) {
            if (spritesCount == 0)throw std::invalid_argument("spritesCount cannot be 0");
            if (spritesCount > 8192)throw std::invalid_argument("spritesCount cannot be 8192");

            renderStates = sf::RenderStates::Default;
            this->renderTarget = renderTarget;
            vertexCount = spritesCount * 6;
            vertices = new sf::Vertex[vertexCount];
        }

        void setRenderTarget(sf::RenderTarget *renderTarget) {
            this->renderTarget = renderTarget;
        }

        void draw(const sf::RectangleShape &sprite) {
            if (index + 6 >= vertexCount) flush();
            if (sprite.getTexture() != renderStates.texture) {
                flush();
                renderStates.texture = sprite.getTexture();
            }

            const sf::Color color = sprite.getFillColor();
            const auto texX = static_cast<float>(sprite.getTextureRect().left);
            const auto texY = static_cast<float>(sprite.getTextureRect().top);
            const auto texW = static_cast<float>(sprite.getTextureRect().width);
            const auto texH = static_cast<float>(sprite.getTextureRect().height);
            const sf::Vector2f position = sprite.getPosition();

            vertices[index].position = sprite.getPoint(0) + position;
            vertices[index].color = color;
            vertices[index].texCoords = {texX, texY};
            ++index;

            vertices[index].position = sprite.getPoint(1) + position;
            vertices[index].color = color;
            vertices[index].texCoords = {texX + texW, texY};
            ++index;

            vertices[index].position = sprite.getPoint(3) + position;
            vertices[index].color = color;
            vertices[index].texCoords = {texX, texY + texH};
            ++index;

            vertices[index].position = sprite.getPoint(1) + position;
            vertices[index].color = color;
            vertices[index].texCoords = {texX + texW, texY};
            ++index;

            vertices[index].position = sprite.getPoint(2) + position;
            vertices[index].color = color;
            vertices[index].texCoords = {texX + texW, texY + texH};
            ++index;

            vertices[index].position = sprite.getPoint(3) + position;
            vertices[index].color = color;
            vertices[index].texCoords = {texX, texY + texH};
            ++index;
        }

        void flush() {
            if (renderTarget) {
                renderTarget->draw(vertices, index, sf::PrimitiveType::Triangles, renderStates);
                index = 0;
            }
        }

        ~SpriteBatch() {
            delete[] vertices;
        }
    };
} // endora

#endif //SPRITEBATCH_HPP
