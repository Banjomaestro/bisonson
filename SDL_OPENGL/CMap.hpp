//
//  CMap.hpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef CMap_hpp
#define CMap_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include "CTile.hpp"
#include "CSurface.hpp"

class CMap {
    
public:
    SDL_Surface* Surf_Tileset;
    GLuint ID_Tileset;
    
private:
    std::vector<CTile> TileList;
    
public:
    CMap();
    
public:
    bool OnLoad(char* File);
    void OnRender(int MapX, int MapY);
    
public:
    CTile* GetTile(int X, int Y);
};

#endif /* CMap_hpp */
