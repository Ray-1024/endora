//
// Created by Ray_1024 on 06.07.2025.
//

#ifndef ECS_HPP
#define ECS_HPP

#include <memory>
#include <vector>
#include "engine/ecs/System.hpp"
#include "engine/utils/context/Context.hpp"
#include "engine/utils/context/ContextObject.hpp"

namespace endora::ecs {
    class Ecs final : public utils::ContextObject {
        std::vector<std::shared_ptr<System> > startupSystems;
        std::vector<std::shared_ptr<System> > updateSystems;
        std::vector<std::shared_ptr<System> > shutdownSystems;

        static void resolveDependencies(const std::vector<std::shared_ptr<ecs::System> > &systems) {
            for (const auto &system: systems)
                system->postConstruct();
        }

        static void update(const std::vector<std::shared_ptr<ecs::System> > &systems) {
            for (const auto &system: systems)
                system->update();
        }

    public:
        explicit Ecs(const std::shared_ptr<utils::Context> &context) : ContextObject(context) {
        }

        void postConstruct() override {
            resolveDependencies(startupSystems);
            update(startupSystems);
            resolveDependencies(updateSystems);
        }

        template<typename T>
        Ecs &addStartupSystem() {
            startupSystems.emplace_back(context->createSingleton<T, utils::Context>());
            return *this;
        }

        template<typename T>
        Ecs &addUpdateSystem() {
            updateSystems.emplace_back(context->createSingleton<T, utils::Context>());
            return *this;
        }

        template<typename T>
        Ecs &addShutdownSystem() {
            shutdownSystems.emplace_back(context->createSingleton<T, utils::Context>());
            return *this;
        }

        void processUpdateSystems() const {
            update(updateSystems);
        }

        void preDestruct() override {
            resolveDependencies(shutdownSystems);
            update(shutdownSystems);
        }
    };
} // endora

#endif //ECS_HPP
