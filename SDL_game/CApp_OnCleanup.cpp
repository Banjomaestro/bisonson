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
    
    TTF_Quit();
    SDL_Quit();
}
