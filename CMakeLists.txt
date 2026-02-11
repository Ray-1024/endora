cmake_minimum_required(VERSION 4.1)
project(endora)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.6.2 COMPONENTS system window graphics audio network REQUIRED)

include_directories("src")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/src/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME}
        ${HEADERS}
        ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-network sfml-system sfml-window)