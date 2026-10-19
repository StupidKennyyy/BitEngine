#include <SDL3/SDL.h>
#include <corecrt_search.h>
#include "include/engine.h"

int main()
{
    
Engine engine = {NULL};
    
    if (!Engine_Init(&engine, 640, 480))
    {
        return 1;
    }

    Engine_Run(&engine);

    Engine_Quit(&engine);

    return 0;
}
