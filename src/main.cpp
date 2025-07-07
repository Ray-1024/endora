#include <memory>
#include <engine/ecs/window/WindowSystem.hpp>

#include "engine/application/Application.hpp"
#include "engine/application/ApplicationConfiguration.hpp"
#include "engine/ecs/graphics/GraphicsSystem.hpp"
#include "engine/ecs/input/InputSystem.hpp"
#include "engine/ecs/time/TimeSystem.hpp"
#include "engine/utils/context/Context.hpp"

int main() {
    const auto context = std::make_shared<endora::utils::Context>();
    context->registerSingleton(context);

    const auto applicationConfiguration = context->createSingleton<endora::ApplicationConfiguration>();
    applicationConfiguration->setTitle("Endora");
    applicationConfiguration->setFps(60);
    applicationConfiguration->setFullscreen(true);

    const auto ecs = context->createSingleton<endora::ecs::Ecs, endora::utils::Context>();
    ecs->addStartupSystem<endora::ecs::WindowSystem>();
    ecs->addUpdateSystem<endora::ecs::TimeSystem>();
    ecs->addUpdateSystem<endora::ecs::InputSystem>();
    ecs->addUpdateSystem<endora::ecs::GraphicsSystem>();

    const auto application = context->createSingleton<endora::Application, endora::utils::Context>();
    application->run();
}
