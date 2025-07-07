//
// Created by Ray_1024 on 22.06.2025.
//

#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include "engine/utils/context/Context.hpp"
#include "engine/utils/context/ContextObject.hpp"

namespace endora::ecs {
    class System : public utils::ContextObject {
    public:
        explicit System(const std::shared_ptr<endora::utils::Context> &context) : ContextObject(context) {
        }

        virtual void update() = 0;

        ~System() override = default;
    };
} // endora

#endif //SYSTEM_HPP
