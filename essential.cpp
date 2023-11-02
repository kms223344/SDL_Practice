#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>

#include "essential.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gImg = NULL;

bool init()
{
    bool ok = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        ok = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            ok = false;
        }
        else
        {
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                ok = false;
            }
            else gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return ok; 
}

SDL_Surface* loadSurface(std::string path)
{
    //SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL) printf("Unable to load image %s!! SDL_IMAGE_ERROR: %s\n", path.c_str(), IMG_GetError());
    else
    {
        SDL_Surface *tmp = loadedSurface;
        loadedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if(loadedSurface == NULL)
            printf("Unable to optimize image %s!! SDL_ERROR: %s\n", path.c_str(), SDL_GetError());
        
        SDL_FreeSurface(tmp); 
    }
    return loadedSurface;
}

bool loadMedia()
{
    bool ret = true;
    gImg = loadSurface("res/loaded.png");
    
    if(gImg == NULL)
    {
		printf( "Failed to load PNG image!\n" );
		ret = false;
    }
    
    return ret;
}

void close()
{
    SDL_FreeSurface(gImg);
    gImg = NULL;
    
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    
    SDL_Quit();
}
