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
    
    bool OnLoad(char* File, int playerNum);
    void OnLoop();
    void OnRender();
    void OnCleanup();
    void OnAnimate();
    bool OnCollision(CEntity* Entity);
    void unSelect();
};

#endif /* CPlayer_hpp */
