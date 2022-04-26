//
//  CApp_OnEvent.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

void CApp::OnEvent(SDL_Event *Event) {
    CEvent::OnEvent(Event);
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch (sym) {
        case SDLK_LEFT:
            Player.MoveLeft = true;
            break;
            
        case SDLK_RIGHT:
            Player.MoveRight = true;
            break;
            
        case SDLK_SPACE:
            Player.Jump();
            break;
            
        default:
            break;
    }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch (sym) {
        case SDLK_LEFT:
            Player.MoveLeft = false;
            break;
            
        case SDLK_RIGHT:
            Player.MoveRight = false;
            break;
            
        default:
            break;
    }
}

void CApp::OnExit() {
    Running = false;
}
