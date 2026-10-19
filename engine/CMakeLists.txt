add_library(BitEngineCore STATIC src/engine.c)

target_include_directories(BitEngineCore PUBLIC include)

target_link_libraries(
    BitEngineCore PUBLIC SDL3::SDL3
)
