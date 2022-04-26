//
//  main.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include <iostream>
#include "CApp.h"

CApp::CApp(char* path) {
    char * temp = nullptr;
    temp = strrchr(path, '/');
    if (!temp) {
        temp = strrchr(path, '\\');
    }
    *++temp = '\0';
    Abs_path = path;
    Surf_Display = NULL;
    Running = true;
    TTF_Init();
}

int CApp::OnExecute() {
    if (OnInit()==false)
        return -1;
    
    SDL_Event Event;
    
    while (Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        
        OnLoop();
        OnRender();
    }
    
    OnCleanup();
    
    return 0;
}

int main(int argc, char * argv[]) {
    CApp theApp((char *) argv[0]);
    return theApp.OnExecute();
}
