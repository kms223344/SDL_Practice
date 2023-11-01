#include <SDL.h>
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
            SDL_Event e; bool quit = false;
            gCurrentSurface = gKeyPressSurfaces[Key_Press_Surface_Default];
            while(!quit)
            {
                while(SDL_PollEvent(&e))
                {
                    if(e.type == SDL_QUIT) quit = true;
                    else if(e.type == SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                        {
                        case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[Key_Press_Surface_Up];
                            printf("Up\n");
                            break;
                        case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[Key_Press_Surface_Down];
                            printf("Down\n");
                            break;
                        case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[Key_Press_Surface_Left];
                            printf("Left\n");
                            break; 
                        case SDLK_RIGHT:
                            gCurrentSurface = gKeyPressSurfaces[Key_Press_Surface_Right];
                            printf("Right\n");
                            break;
                            
                        default:
                            gCurrentSurface = gKeyPressSurfaces[Key_Press_Surface_Default];
                        }
                    }
                }
                SDL_Rect strechRect = {SCREEN_WIDTH/3, SCREEN_HEIGHT/3,SCREEN_WIDTH/3, SCREEN_HEIGHT/3};
                SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &strechRect);
                SDL_UpdateWindowSurface(gWindow);
            } 
        } 
    }
    close();
    return 0;
}
