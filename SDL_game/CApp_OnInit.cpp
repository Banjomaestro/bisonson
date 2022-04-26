//
//  CApp_OnInit.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <stdio.h>
#include "CApp.h"

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING)<0)
        return false;
    
    SDL_WM_SetCaption("My Game Window", "game");
    if ((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    
    char img_name[] = "img/yoshi.png";
    char img_Path[strlen(Abs_path) + strlen(img_name)];
    strcpy(img_Path, Abs_path);
    strcat(img_Path + strlen(img_Path), img_name);
    
    if ((Player.OnLoad(img_Path, 64, 64, 8, false)) == false) {
        return false;
    }
    
    if ((Player2.OnLoad(img_Path, 64, 64, 8, false)) == false) {
        return false;
    }
    
    char file_name[] = "map/1.area";
    if (CArea::AreaControl.OnLoad(file_name, Abs_path) == false) {
        return false;
    }
    
    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
    
    Player.X = 200;
    Player2.X = 300;
    
    CEntity::EntityList.push_back(&Player);
    CEntity::EntityList.push_back(&Player2);
    
    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);
    
    return true;
}
