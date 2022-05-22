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
    bool selected;
    
public:
    CPlayer();
    
    bool OnLoad(char* File, int Width, int Height, int MaxFrames, float jumpFactor);
    void OnLoop();
    void OnRender();
    void OnCleanup();
    void OnAnimate();
    bool OnCollision(CEntity* Entity);
};

#endif /* CPlayer_hpp */
