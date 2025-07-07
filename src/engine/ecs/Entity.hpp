//
// Created by Ray_1024 on 06.07.2025.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

#include "engine/ecs/Component.hpp"

namespace endora::ecs {
    class Entity final : public std::enable_shared_from_this<Entity> {
    protected:
        std::unordered_map<std::type_index, std::shared_ptr<Component> > components;

    public:
        Entity();

        template<class T>
        Entity &addComponent(const std::shared_ptr<Component> &component) {
            static_assert(std::is_base_of_v<Component, T>);
            component->setEntity(weak_from_this());
            components[typeid(T)] = component;
            return *this;
        }

        template<class T>
        std::shared_ptr<T> getComponent() {
            static_assert(std::is_base_of_v<Component, T>);
            if (!components.contains(typeid(T))) {
                return nullptr;
            }
            return components[typeid(T)];
        }

        template<class T>
        Entity &removeComponent() {
            static_assert(std::is_base_of_v<Component, T>);
            if (components.contains(typeid(T))) {
                components.erase(typeid(T));
            }
            return *this;
        }

        ~Entity() = default;
    };
}

// endora

#endif //ENTITY_HPP
