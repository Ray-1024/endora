cmake_minimum_required(VERSION 4.1)
project(endora)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "lib/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.6.2 REQUIRED COMPONENTS graphics window system audio network)

add_executable(${PROJECT_NAME}
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)