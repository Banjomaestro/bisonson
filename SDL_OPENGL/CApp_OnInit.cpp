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
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

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
    
    //////////////
    
//    char img_name[] = "img/yoshi.png";
//    char img_Path[strlen(Abs_path) + strlen(img_name)];
//    strcpy(img_Path, Abs_path);
//    strcat(img_Path + strlen(img_Path), img_name);
//
//    if ((Player.OnLoad(img_Path, 64, 64, 8, false)) == false) {
//        return false;
//    }
//
//    if ((Player2.OnLoad(img_Path, 64, 64, 8, false)) == false) {
//        return false;
//    }
//
//    char file_name[] = "map/1.area";
//    if (CArea::AreaControl.OnLoad(file_name, Abs_path) == false) {
//        return false;
//    }
//
//    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
//
//    Player.X = 200;
//    Player2.X = 300;
//
//    CEntity::EntityList.push_back(&Player);
//    CEntity::EntityList.push_back(&Player2);
//
//    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
//    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);
    
    ///////////////
    
    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    tabSurf[0] = IMG_Load("doc/numbers/0.png");
    tabSurf[1] = IMG_Load("doc/numbers/1.png");
    tabSurf[2] = IMG_Load("doc/numbers/2.png");
    tabSurf[3] = IMG_Load("doc/numbers/3.png");
    tabSurf[4] = IMG_Load("doc/numbers/4.png");
    tabSurf[5] = IMG_Load("doc/numbers/5.png");
    tabSurf[6] = IMG_Load("doc/numbers/6.png");
    tabSurf[7] = IMG_Load("doc/numbers/7.png");
    tabSurf[8] = IMG_Load("doc/numbers/8.png");
    tabSurf[9] = IMG_Load("doc/numbers/9.png");
    tabSurf[10] = IMG_Load("doc/numbers/colon.png");
    glGenTextures(11, IDtext);
    for (int i = 0; i < 11; i++) {
        glBindTexture(GL_TEXTURE_2D, IDtext[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, tabSurf[i]->w, tabSurf[i]->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, tabSurf[i]->pixels);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    
    return true;
}
