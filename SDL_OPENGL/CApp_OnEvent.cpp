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
    if(!isMenu){
        printf("whattt");
        switch (sym) {
            case SDLK_LEFT:
                PlayerList[PlayerNB]->MoveLeft = true;
                break;
                
            case SDLK_RIGHT:
                PlayerList[PlayerNB]->MoveRight = true;
                break;
                
            case SDLK_SPACE:
                PlayerList[PlayerNB]->Jump();
                break;
                
            case SDLK_TAB:
                PlayerList[PlayerNB]->unSelect();
                PlayerNB = (PlayerNB+1)%PlayerList.size();
                PlayerList[PlayerNB]->selected = true;
                CCamera::CameraControl.SetTarget(&PlayerList[PlayerNB]->X, &PlayerList[PlayerNB]->Y);
                break;
                
            default:
                break;
            }
    }else
        if(sym==13){
            isMenu = false;
            loadLevel = true;
        }
}

void CApp::OnKeyUp(SDL_Keycode sym) {
    if(!isMenu){
        switch (sym) {
            case SDLK_LEFT:
                PlayerList[PlayerNB]->MoveLeft = false;
                break;
                
            case SDLK_RIGHT:
                PlayerList[PlayerNB]->MoveRight = false;
                break;
                
            default:
                break;
        }
    }
}

void CApp::OnExit() {
    Running = false;
}
