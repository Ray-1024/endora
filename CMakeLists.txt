cmake_minimum_required(VERSION 3.30)
project(endora)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "C:\\Users\\Ray_1024\\Libraries\\SFML-2.6.2\\lib\\cmake\\SFML")
find_package(SFML 2.6.2 REQUIRED COMPONENTS graphics audio network system window)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
include_directories(src)

file(GLOB HDRS "src/*.h" "src/*.hpp")
file(GLOB SRCS "src/*.cpp")
add_executable(${PROJECT_NAME} ${HDRS} ${SRCS}
        src/engine/application/ApplicationConfiguration.hpp
        src/engine/application/Application.hpp
        src/engine/ecs/Entity.hpp
        src/engine/ecs/Component.hpp
        src/engine/ecs/System.hpp
        src/engine/ecs/Ecs.hpp
        src/engine/utils/codegeneration/GetterSetter.hpp
        src/engine/utils/context/Context.hpp
        src/engine/utils/context/ContextObject.hpp
        src/engine/ecs/graphics/GraphicsSystem.hpp
        src/engine/ecs/time/TimeSystem.hpp
        src/engine/ecs/input/InputSystem.hpp
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
