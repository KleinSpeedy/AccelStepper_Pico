cmake_minimum_required(VERSION 3.20)
include(pico_sdk_import.cmake)

project(AccelStepper_Pico LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

pico_sdk_init()

add_library(${PROJECT_NAME}
    src/AccelStepper.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC pico_stdlib)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
