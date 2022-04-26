//
//  CApp.h
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#ifndef CApp_h
#define CApp_h

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "CPlayer.hpp"
#include "CSurface.hpp"
#include "CAnimation.hpp"
#include "CEvent.hpp"
#include "CEntity.hpp"
#include "CArea.hpp"
#include "CCamera.hpp"

class CApp : public CEvent {
    
private:
    char * Abs_path;
    bool Running;
    SDL_Surface* Surf_Display;
    
private:
    CPlayer Player;
    CPlayer Player2;
    
public:
    CApp(char * path);
    int OnExecute();
    
public:
    bool OnInit();
    void drawText(SDL_Surface* Surf_Display, char* string, int size, short x, short y, uint8_t R, uint8_t G, uint8_t B);
    void OnEvent(SDL_Event* Event);
    void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
    void OnExit();
    void OnLoop();
    void OnRender();
    void OnCleanup();
    
};

#endif /* CApp_h */
