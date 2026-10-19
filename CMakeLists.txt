cmake_minimum_required(VERSION 3.15)

project(BitEngine LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(include/SDL EXCLUDE_FROM_ALL)

add_subdirectory(engine)

add_executable(BitEngine
    engine/main.c
)

target_include_directories(BitEngine PRIVATE
    include
)

target_link_libraries(BitEngine PRIVATE
    SDL3::SDL3
    BitEngineCore
)

add_custom_command(TARGET BitEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL3::SDL3>
    $<TARGET_FILE_DIR:BitEngine>
)
