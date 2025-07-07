//
// Created by Ray_1024 on 23.06.2025.
//

#ifndef TIMESYSTEM_HPP
#define TIMESYSTEM_HPP
#include <chrono>

#include "engine/ecs/System.hpp"
#include "engine/utils/codegeneration/GetterSetter.hpp"

namespace endora::ecs {
    class TimeSystem final : public endora::ecs::System {
        double deltaTime{};
        GETTER(double, deltaTime, DeltaTime)
        uint32_t fps{};
        GETTER(uint32_t, fps, Fps)
        uint32_t frameNumberPerSecond{};
        std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> currentTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> lastFpsUpdateTime;

    public:
        explicit TimeSystem(const std::shared_ptr<endora::utils::Context> &context)
            : System(context) {
            currentTime = std::chrono::high_resolution_clock::now();
            lastFpsUpdateTime = currentTime;
        }

        void postConstruct() override {
        }
        void preDestruct() override {
        }


        void update() override {
            lastTime = currentTime;
            currentTime = std::chrono::high_resolution_clock::now();
            deltaTime = std::chrono::duration_cast<std::chrono::duration<double> >(currentTime - lastTime).count();
            ++frameNumberPerSecond;
            if (std::chrono::duration_cast<std::chrono::duration<double> >(currentTime - lastFpsUpdateTime).count() >=
                1.0) {
                fps = frameNumberPerSecond;
                frameNumberPerSecond = 0;
                lastFpsUpdateTime = currentTime;
            }
        }

        ~TimeSystem() override = default;
    };
} // endora

#endif //TIMESYSTEM_HPP
