//
//  CApp_OnRender.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

void CApp::OnRender() {
    CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
    
    for (int i = 0; i < CEntity::EntityList.size(); i++) {
        if (!CEntity::EntityList[i]) continue;
        
        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
    
    std::string FPS_Str = std::to_string(CFPS::FPSControl.GetFPS());
    char const *FPS = FPS_Str.c_str();
    drawText(Surf_Display, (char*) FPS, 50, 200, 200, 255, 255, 255);
    SDL_RenderPresent(sdlRenderer);
}
