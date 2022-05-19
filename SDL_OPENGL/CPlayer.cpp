//
//  CPlayer.cpp
//  SDL_game
//
//  Created by MissBidule on 02/01/2022.
//

#include "CPlayer.hpp"

CPlayer::CPlayer() {
    Type = ENTITY_TYPE_PLAYER;
    Col_Width_L = 15;
    Col_Width_R = 32;
    Col_Height_T = 25;
    Col_Height_B = 37;
}

bool CPlayer::OnLoad(char *File, int Width, int Height, int MaxFrames) {
    if (!CEntity::OnLoad(File, Width, Height, MaxFrames)) return false;
    
    return true;
}

void CPlayer::OnLoop() {
    CEntity::OnLoop();
}

void CPlayer::OnRender() {
    CEntity::OnRender();
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
