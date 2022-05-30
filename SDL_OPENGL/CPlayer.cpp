//
//  CPlayer.cpp
//  SDL_game
//
//  Created by MissBidule on 02/01/2022.
//

#include "CPlayer.hpp"

CPlayer::CPlayer() {
    Type = ENTITY_TYPE_PLAYER;
    selected = false;
}

bool CPlayer::OnLoad(char* File, int playerNum, int X, int Y, bool selected) {
    
    if (!CEntity::OnLoad(File, playerNum, X, Y)) return false;
    this->selected = selected;
    return true;
}

void CPlayer::OnLoop() {
    CEntity::OnLoop();
}

void CPlayer::OnRender() {
    CEntity::OnRender();
    
    if (selected) {
        CSurface::drawIndicator(X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), Width, Height,1);
    }
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
    //rien
    
    return true;
}

void CPlayer :: unSelect(){
    selected = false;
    MoveLeft = false;
    MoveRight = false;    
}
