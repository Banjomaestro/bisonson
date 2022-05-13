//
//  CAnimation.hpp
//  animation_SDL
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef CAnimation_hpp
#define CAnimation_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class CAnimation {

private:
    int CurrentFrame;
    int FrameInc;
    
private:
    int FrameRate;//Milliseconds
    long OldTime;
    
public:
    int MaxFrames;
    bool Oscillate;
    
public:
    CAnimation();
    void OnAnimate();
    
public:
    void SetFrameRate(int Rate);
    void SetCurrentFrame(int Frame);
    int GetCurrentFrame();

};

#endif /* CAnimation_hpp */
