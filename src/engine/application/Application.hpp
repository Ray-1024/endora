//
// Created by Ray_1024 on 16.06.2025.
//

#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <memory>

#include "engine/ecs/Ecs.hpp"
#include "engine/utils/context/Context.hpp"


namespace endora {
    class Application final : public utils::ContextObject {
        std::shared_ptr<ecs::Ecs> ecs;
        bool running;

    public:
        explicit Application(const std::shared_ptr<utils::Context> &context): ContextObject(context) {
            ecs = context->resolveOrCreateSingleton<ecs::Ecs, utils::Context>();
            running = true;
        }

        void run() const {
            ecs->postConstruct();
            while (running)
                ecs->processUpdateSystems();
            ecs->preDestruct();
        }

        void stop() {
            running = false;
        }

        ~Application() override = default;

        void postConstruct() override {
        }

        void preDestruct() override {
        }
    };
} // endora

#endif //APPLICATION_HPP
