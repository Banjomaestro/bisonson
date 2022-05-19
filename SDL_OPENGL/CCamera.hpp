//
//  CCamera.hpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef CCamera_hpp
#define CCamera_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Define.h"

enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class CCamera {
    
public:
    static CCamera CameraControl;
    
private:
    float X;
    float Y;
    
    float* TargetX;
    float* TargetY;
    
public:
    int TargetMode;
    
public:
    CCamera();
    
public:
    void OnMove(float MoveX, float MoveY);
    
public:
    float GetX();
    float GetY();
    int GetTargetMode();
    
public:
    void SetPos(float X, float Y);
    void SetTarget(float* X, float* Y);
};

#endif /* CCamera_hpp */
