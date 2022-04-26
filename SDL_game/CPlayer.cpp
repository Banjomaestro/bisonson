//
//  CPlayer.cpp
//  SDL_game
//
//  Created by MissBidule on 02/01/2022.
//

#include "CPlayer.hpp"

CPlayer::CPlayer() {
    Type = ENTITY_TYPE_PLAYER;
    Col_Width = 16;
    Col_X = 9;
    Col_Height = 1;
    Col_Y = 0;
}

bool CPlayer::OnLoad(char *File, int Width, int Height, int MaxFrames, bool transparency, int R, int G, int B) {
    if (!CEntity::OnLoad(File, Width, Height, MaxFrames, transparency, R, G, B)) return false;
    
    return true;
}

void CPlayer::OnLoop() {
    CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Surface *Surf_Display) {
    CEntity::OnRender(Surf_Display);
}

void CPlayer::OnCleanup() {
    CEntity::OnCleanup();
}

void CPlayer::OnAnimate() {
    if (SpeedX != 0) {
        Anim_Control.MaxFrames = 8;
    }
    else {
        Anim_Control.MaxFrames = 0;
    }
    
    CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity *Entity) {
    Jump();
    
    return true;
}
