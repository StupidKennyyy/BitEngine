#ifndef ENGINE_H
#define ENGINE_H

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>
#include <corecrt_search.h>
#include <stdbool.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
} Engine;

bool Engine_Init(Engine *engine, int window_width, int window_height);

void Engine_Run(Engine *engine);

void Engine_Quit(Engine *engine);

#endif // ENGINE_H


