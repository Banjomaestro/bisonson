//
//  CApp_OnCleanup.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

void CApp::OnCleanup() {
    for (int i = 0; i < CEntity::EntityList.size(); i++) {
        if (!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnCleanup();
    }

    CEntity::EntityList.clear();

    CArea::AreaControl.OnCleanup();
    
    /* Liberation des ressources associees a la SDL */
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(Surf_Display);
    our_font.clean();
    glDeleteTextures(1, IDtext);
    for (int i = 0; i < 11; i++) {
        SDL_FreeSurface(tabSurf[i]);
    }
    SDL_Quit();
    
    //TTF_Quit();
    SDL_Quit();
}
