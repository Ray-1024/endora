//
// Created by Ray_1024 on 06.07.2025.
//

#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <memory>

#include "engine/ecs/Entity.hpp"
#include "engine/utils/codegeneration/GetterSetter.hpp"

namespace endora::ecs {
    class Component {
    protected:
        std::weak_ptr<ecs::Entity> entity;
        GETSET(std::weak_ptr<ecs::Entity>, entity, Entity)

    public:
        explicit Component() = default;

        virtual ~Component() = default;
    };
} // endora

#endif //COMPONENT_HPP
