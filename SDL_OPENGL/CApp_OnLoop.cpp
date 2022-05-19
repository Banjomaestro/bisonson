//
//  CApp_OnLoop.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

void CApp::OnLoop() {
    CFPS::FPSControl.OnLoop();
    for (int i = 0; i < CEntity::EntityList.size(); i++) {
        if (!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }

    //Collision Events
    for (int i = 0; i < CEntityCol::EntityColList.size(); i++) {
        CEntity* EntityA = CEntityCol::EntityColList[i].EntityA;
        CEntity* EntityB = CEntityCol::EntityColList[i].EntityB;

        if (EntityA == NULL || EntityB == NULL) continue;

        if (EntityA->OnCollision(EntityB)) {
            EntityB->OnCollision(EntityA);
        }
    }

    CEntityCol::EntityColList.clear();
    
}
