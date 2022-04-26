//
//  CPlayer.hpp
//  SDL_game
//
//  Created by MissBidule on 02/01/2022.
//

#ifndef CPlayer_hpp
#define CPlayer_hpp

#include <stdio.h>
#include "CEntity.hpp"

class CPlayer : public CEntity {
    
public:
    CPlayer();
    
    bool OnLoad(char* File, int Width, int Height, int MaxFrames, bool transparency, int R=0, int G=0, int B=0);
    void OnLoop();
    void OnRender(SDL_Surface* Surf_Display);
    void OnCleanup();
    void OnAnimate();
    bool OnCollision(CEntity* Entity);
};

#endif /* CPlayer_hpp */
