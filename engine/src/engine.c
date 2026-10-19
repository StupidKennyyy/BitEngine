#include "SDL3/SDL_error.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_oldnames.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <corecrt_search.h>
#include <stdbool.h>
#include <SDL3/sdl.h>
#include <stdio.h>

#include "engine.h"

bool Engine_Init(Engine *engine, int window_width, int window_height)
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL Init failed: %s\n", SDL_GetError());
        return 0;
    }
    else 
    {
        printf("SDL Init Successful\n");
    }
    if(!SDL_CreateWindowAndRenderer("BitEngine", window_width, window_height, SDL_WINDOW_RESIZABLE, &engine->window, &engine->renderer))
    {
        printf("SDL CreateWindowAndRenderer failed: %s\n", SDL_GetError());
        return 0;
    }
    else 
    {
        printf("SDL Init Successful\n");
    }

    
    engine->running = true;

    return 1;

}

void Engine_Run(Engine *engine)
{
    SDL_Event event;

    SDL_FRect rect;
    rect.x = 10.0f;
    rect.y = 20.0f;
    rect.w = 100.0f;
    rect.h = 50.0f;


    SDL_Renderer *renderer = engine->renderer;

    while (engine->running) {

        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            engine->running = false;
        }

        
        SDL_SetRenderDrawColor(renderer, 50, 100, 200, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);

    }

}

void Engine_Quit(Engine *engine)
{
    SDL_DestroyRenderer(engine->renderer);
    SDL_DestroyWindow(engine->window);

    SDL_Quit();
}

