cmake_minimum_required(VERSION 3.30)
project(endora)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.6.2 REQUIRED COMPONENTS graphics audio network system window)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
include_directories(src)

file(GLOB HDRS "src/*.h" "src/*.hpp")
file(GLOB SRCS "src/*.cpp")
add_executable(${PROJECT_NAME} ${HDRS} ${SRCS}
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
