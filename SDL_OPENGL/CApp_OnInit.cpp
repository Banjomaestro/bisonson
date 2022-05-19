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
    
    char img_name[] = "img/yoshi.png";
    char img_Path[strlen(Abs_path) + strlen(img_name)];
    strcpy(img_Path, Abs_path);
    strcat(img_Path + strlen(img_Path), img_name);

    if ((Player.OnLoad(img_Path, 64, 64, 8)) == false) {
        return false;
    }

    if ((Player2.OnLoad(img_Path, 64, 64, 8)) == false) {
        return false;
    }

    char file_name[] = "map/1.area";
    if (CArea::AreaControl.OnLoad(file_name, Abs_path) == false) {
        return false;
    }
    
    our_font.init("font/Sans.ttf", 25 /* size */);

    Player.X = 100;
    Player.Y = -150;
    Player2.X = 300;
    Player2.Y = -150;

    CEntity::EntityList.push_back(&Player);
    CEntity::EntityList.push_back(&Player2);

    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    //CCamera::CameraControl.SetPos(WINDOW_WIDTH/2-TILE_SIZE/2, -WINDOW_HEIGHT/2+TILE_SIZE/2);
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);
    
    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    return true;
}
