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

void CApp::onWindowResized(unsigned int width, unsigned int height) {
    CEvent::onWindowResized(width, height);
}


void CApp::OnKeyDown(SDL_Keycode sym) {
    printf("touche pressee (code = %d)\n", sym);
    if ((sym == SDLK_q || sym == SDLK_ESCAPE))
        OnExit();
    switch (sym) {
        case SDLK_LEFT:
            //Player.MoveLeft = true;
            break;
            
        case SDLK_RIGHT:
            //Player.MoveRight = true;
            break;
            
        case SDLK_SPACE:
            //Player.Jump();
            break;
            
        default:
            break;
    }
}

void CApp::OnKeyUp(SDL_Keycode sym) {
    switch (sym) {
        case SDLK_LEFT:
            //Player.MoveLeft = false;
            break;
            
        case SDLK_RIGHT:
            //Player.MoveRight = false;
            break;
            
        default:
            break;
    }
}

void CApp::OnExit() {
    Running = false;
}
