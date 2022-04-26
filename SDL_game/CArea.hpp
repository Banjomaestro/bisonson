//
//  CArea.hpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef CArea_hpp
#define CArea_hpp

#include <stdio.h>
#include "CMap.hpp"

class CArea {
    
public:
    static CArea AreaControl;
    
public:
    std::vector<CMap>   MapList;
    
private:
    int AreaSize;
    SDL_Surface* Surf_Tileset;
    
public:
    CArea();
    bool OnLoad(char* File, char* Abs_path);
    void OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
    void OnCleanup();
    
public:
    CMap* GetMap(int X, int Y);
    CTile* GetTile(int X, int Y);
};

#endif /* CArea_hpp */
