#pragma once
#include <SDL.h>
#include <string>

bool init();
bool loadMedia();
void close();

SDL_Surface* loadSurface(std::string path);


enum KeyPressSurfaces
{
    Key_Press_Surface_Default,
    Key_Press_Surface_Up,
    Key_Press_Surface_Down,
    Key_Press_Surface_Left,
    Key_Press_Surface_Right,
    Key_Press_Surface_Total
};

extern SDL_Window *gWindow;
extern SDL_Surface *gScreenSurface;
extern SDL_Surface *gKeyPressSurfaces[Key_Press_Surface_Total];
extern SDL_Surface *gCurrentSurface;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
