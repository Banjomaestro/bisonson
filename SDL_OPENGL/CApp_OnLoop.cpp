//
//  CApp_OnLoop.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

void CApp::OnLoop() {
    //CFPS::FPSControl.OnLoop();
//    for (int i = 0; i < CEntity::EntityList.size(); i++) {
//        if (!CEntity::EntityList[i]) continue;
//
//        CEntity::EntityList[i]->OnLoop();
//    }
//
//    //Collision Events
//    for (int i = 0; i < CEntityCol::EntityColList.size(); i++) {
//        CEntity* EntityA = CEntityCol::EntityColList[i].EntityA;
//        CEntity* EntityB = CEntityCol::EntityColList[i].EntityB;
//
//        if (EntityA == NULL || EntityB == NULL) continue;
//
//        if (EntityA->OnCollision(EntityB)) {
//            EntityB->OnCollision(EntityA);
//        }
//    }
//
//    CEntityCol::EntityColList.clear();
    
    /* Placer ici le code de dessin */

    int width = 0;
    int height = 0;

    SDL_GetWindowSize(Surf_Display,&width,&height);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(255.0, 255.0, 255.0, 0.0);

        glPushMatrix();
        glLoadIdentity();

        // Blue text
        glColor3ub(0,0,0xff);

        iterations ++;

        if(iterations>100){
            glfreetype::print(our_font, width/2 +(iterations%1000)/4 /* xpos */,height/2+(iterations%1000)/4 /* ypos */, description.substr(0,(iterations-90)/10),100);
        }

        glPopMatrix();


    /*
    for (int i = -4; i < 4; i++) {
        int id = 0;
        if (i == -4)
            id = heures/10;
        else if (i == -3)
            id = heures%10;
        else if (i == -1)
            id = minutes/10;
        else if (i == 0)
            id = minutes%10;
        else if (i == 2)
            id = secondes/10;
        else if (i == 3)
            id = secondes%10;
        else
            id = 10;
        
        CSurface::drawTexture(IDtext[id], 13+i*26, 0, 26, 42, 0.6);
    
    }
    
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);*/
}
