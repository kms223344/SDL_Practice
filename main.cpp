#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>

#include "essential.h"
//init, loadMedia, close

int main( int argc, char* args[] )
{
    if(!init()) printf("Failed to Initiate!\n");
    else
    {
        if(!loadMedia()) printf("Failed to Load Media!\n");
        else
        {
            SDL_BlitSurface(gImg, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            
            SDL_Event e; bool quit = false;
            while(!quit)
            {
                while(SDL_PollEvent(&e))
                {
                    if(e.type == SDL_QUIT) quit = true;
                }
            } 
        } 
    }
    close();
    return 0;
}
