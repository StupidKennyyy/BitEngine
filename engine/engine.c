#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <corecrt_search.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL3/sdl.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;



int main()
{
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer("BitEngine", 640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer);
    
    SDL_SetRenderDrawColor(renderer, 50, 100, 200, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;

    while (true) {

        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            break;
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
