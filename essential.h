#pragma once
#include <SDL.h>
#include <string>

bool init();
bool loadMedia();
void close();

SDL_Surface* loadSurface(std::string path);


extern SDL_Window *gWindow;
extern SDL_Surface *gScreenSurface;
extern SDL_Surface *gImg;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
