//
//  CApp_OnInit.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

bool CApp::OnInit() {
    /* Initialisation de la SDL */

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        const char* error = SDL_GetError();
        fprintf(
            stderr,
            "Erreur lors de l'intialisation de la SDL : %s\n", error);

        SDL_Quit();
        return EXIT_FAILURE;
    }

    /* Ouverture d'une fenetre et creation d'un contexte OpenGL */


    SDL_Window* window;
    {
        window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );

        if(NULL == window)
        {
            const char* error = SDL_GetError();
            fprintf(
                stderr,
                "Erreur lors de la creation de la fenetre : %s\n", error);

            SDL_Quit();
            return EXIT_FAILURE;
        }
    }
    
    {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        context = SDL_GL_CreateContext(window);
    
        if(NULL == context)
        {
            const char* error = SDL_GetError();
            fprintf(
                stderr,
                "Erreur lors de la creation du contexte OpenGL : %s\n", error);

            SDL_DestroyWindow(window);
            SDL_Quit();
            return EXIT_FAILURE;
        }
    }
    
    Surf_Display = window;
    
    
    CPlayer* tempPlayer = new CPlayer();
        printf("please print");

    if ((tempPlayer->OnLoad("players/list.txt",1)) == false) {
        return false;
    }

    PlayerList.push_back(tempPlayer);
    
    tempPlayer = new CPlayer();
    if ((tempPlayer->OnLoad("players/list.txt",0)) == false) {
        return false;
    }

    PlayerList.push_back(tempPlayer);
    
    char file_name[] = "map/1.area";
    if (CArea::AreaControl.OnLoad(file_name, Abs_path) == false) {
        return false;
    }
    
    our_font.init("font/Sans.ttf", 25 /* size */);

    PlayerList[0]->X = 100;
    PlayerList[0]->Y = -150;
    PlayerList[0]->selected = true;
    PlayerList[1]->X = 300;
    PlayerList[1]->Y = -150;

    CEntity::EntityList.push_back(PlayerList[0]);
    CEntity::EntityList.push_back(PlayerList[1]);

    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    //CCamera::CameraControl.SetPos(WINDOW_WIDTH/2-TILE_SIZE/2, -WINDOW_HEIGHT/2+TILE_SIZE/2);
    CCamera::CameraControl.SetTarget(&PlayerList[0]->X, &PlayerList[0]->Y);
    
    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!music.openFromFile("sound/night light.wav")){
        return -1; // error
        printf("faillll");
    }
    

    
    return true;
}
