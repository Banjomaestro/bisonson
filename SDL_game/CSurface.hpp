//
//  CSurface.hpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#ifndef CSurface_hpp
#define CSurface_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CSurface {
    
public:
    CSurface();
    
public:
    static SDL_Surface* OnLoad(char* File, bool transparency = false);
    static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
    static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);
    static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

#endif /* CSurface_hpp */
