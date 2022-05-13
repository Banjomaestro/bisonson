//
//  CApp_OnRender.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

void CApp::OnRender() {
    //CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
    
//    for (int i = 0; i < CEntity::EntityList.size(); i++) {
//        if (!CEntity::EntityList[i]) continue;
//
//        CEntity::EntityList[i]->OnRender(Surf_Display);
//    }
    
//    std::string FPS_Str = std::to_string(CFPS::FPSControl.GetFPS());
//    char const *FPS = FPS_Str.c_str();
//    drawText(Surf_Display, (char*) FPS, 50, 200, 200, 255, 255, 255);
    
    /* Echange du front et du back buffer : mise a jour de la fenetre */
    SDL_GL_SwapWindow(Surf_Display);
    
    /* Calcul du temps ecoule */
    Uint32 elapsedTime = SDL_GetTicks() - startTime;
    /* Si trop peu de temps s'est ecoule, on met en pause le programme */
    if(elapsedTime < FRAMERATE_MILLISECONDS)
    {
        SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
    }
}
