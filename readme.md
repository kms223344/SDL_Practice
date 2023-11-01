SDL2 program!

How to build?
1. We should use gcc compiler (specifically, mingw64-12.2)
2. Compile source code with linking the SDL2 Library
 (1) add -l$(path of SDL2 includes) for including SDL2 includes when compile.
 (2) add -L$(path of SDL2 libraries) for linking SDL2 libraries.
 (3) add "-lmingw32 -lSDL2main -lSDL2" for clearify the link sequence
