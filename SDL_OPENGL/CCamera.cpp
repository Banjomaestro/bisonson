//
//  CCamera.cpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#include "CCamera.hpp"

CCamera CCamera::CameraControl;

CCamera::CCamera() {
    X = Y = 0;
    
    TargetX = TargetY = NULL;
    
    TargetMode = TARGET_MODE_NORMAL;
}

void CCamera::OnMove(float MoveX, float MoveY) {
    X += MoveX;
    Y += MoveY;
}

float CCamera::GetX() {
    if (TargetMode == TARGET_MODE_CENTER) {
        return *TargetX;
    }
    
    return X;
}

float CCamera::GetY() {
    if (TargetMode == TARGET_MODE_CENTER) {
        return *TargetY;
    }
        
    return Y;
}

void CCamera::SetPos(float X, float Y) {
    this->X = X;
    this->Y = Y;
}

void CCamera::SetTarget(float *X, float *Y) {
    TargetX = X;
    TargetY = Y;
}

int CCamera::GetTargetMode() {
    return TargetMode;
}
