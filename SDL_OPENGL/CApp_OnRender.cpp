//
//  CApp_OnRender.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//
#include <stdio.h>
#include "CApp.h"

void CApp::OnRender() {
    /* Placer ici le code de dessin */
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(7.0/255,105.0/255,151.0/255,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_TEXTURE_2D);
    
    CArea::AreaControl.OnRender();
    
    for (int i = 0; i < CEntity::EntityList.size(); i++) {
        if (!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnRender();
    }
    
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    
    std::string FPS_Str = std::to_string(CFPS::FPSControl.GetFPS());

    /*Affiche du texte*/
    int middlew = 0;
    int middleh = 0;
    SDL_GetWindowSize(Surf_Display,&middlew,&middleh);

    if(isMenu)
        glfreetype::print(0, 0, 255, our_font, middlew/2 -50 /* xpos */, middleh/2 /* ypos */, "Food vs Humans \npress [Enter] to play !");
    
    if(showFPS)
        glfreetype::print(0, 0, 255, our_font, 30 /* xpos */, 600 /* ypos */, FPS_Str);
    
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
