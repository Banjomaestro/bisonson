//
//  CFPS.hpp
//  SDL_game
//
//  Created by MissBidule on 02/01/2022.
//

#ifndef CFPS_hpp
#define CFPS_hpp

#include <stdio.h>
#include <SDL/SDL.h>

class CFPS {
    
public:
    static CFPS FPSControl;
    
private:
    int OldTime;
    int LastTime;
    
    float SpeedFactor;
    
    int NumFrames;
    int Frames;
    
public:
    CFPS();
    
    void OnLoop();
    
public:
    int GetFPS();
    float GetSpeedFactor();
};

#endif /* CFPS_hpp */
