#include <SDL.h>
#include <stdio.h>
#include "essential.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gKeyPressSurfaces[Key_Press_Surface_Total];
SDL_Surface *gCurrentSurface;

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return false;
        }
        else gScreenSurface = SDL_GetWindowSurface( gWindow );
    }

    return true;
}

SDL_Surface* loadSurface(std::string path)
{
    SDL_Surface *loadSurface = SDL_LoadBMP(path.c_str());
    if(loadSurface == NULL) printf("Unable to load image %s!! SDL_ERROR: %s\n", path.c_str(), SDL_GetError());
    
    return loadSurface;
}

bool loadMedia()
{
    bool ret = true;
    ret = ret && (gKeyPressSurfaces[Key_Press_Surface_Default] = loadSurface("res/press.bmp"));
    ret = ret && (gKeyPressSurfaces[Key_Press_Surface_Up] = loadSurface("res/up.bmp"));
    ret = ret && (gKeyPressSurfaces[Key_Press_Surface_Down] = loadSurface("res/down.bmp"));
    ret = ret && (gKeyPressSurfaces[Key_Press_Surface_Left] = loadSurface("res/left.bmp"));
    ret = ret && (gKeyPressSurfaces[Key_Press_Surface_Right] = loadSurface("res/right.bmp"));
    
    if(!ret)
    {
        printf("Fail to load some images!!\n");
    }
    
    return ret;
}

void close()
{
    for(int i=0;i<Key_Press_Surface_Total; i++)
    {
        SDL_FreeSurface(gKeyPressSurfaces[i]);
        gKeyPressSurfaces[i] = NULL;
    }
    
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    
    SDL_Quit();
}
