//
//  CApp.hpp
//  
//
//  Created by MissBidule on 11/05/2022.
//

#ifndef CApp_h
#define CApp_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#if defined(__APPLE__)
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>

#include "CEvent.hpp"
#include "CSurface.hpp"
#include "CCamera.hpp"
#include "CFPS.hpp"
#include "CArea.hpp"
#include "CEntity.hpp"
#include "CPlayer.hpp"
#include "CAnimation.hpp"
#include "Define.h"
#include "TextRenderer.hpp"
#include "CLevel.hpp"




class CApp : public CEvent {
    
private:
    char * Abs_path;
    bool Running;
    SDL_Window* Surf_Display;
    SDL_GLContext context;
    Uint32 startTime;
    glfreetype::font_data our_font;
    int iterations;
    std::string description;
    int numberOfLevels;
    
    static std::vector<CPlayer*> PlayerList;
    int PlayerNB;
    bool isMenu;
    bool showFPS;
    int levelNum;
    bool loadLevel;
    bool gameEnd;
    CLevel theLevel;
    
public:
    CApp(char * path);
    void onWindowResized(unsigned int width, unsigned int height);
    int OnExecute();
    
    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnKeyDown(SDL_Keycode sym);
    void OnKeyUp(SDL_Keycode sym);
    void OnLButtonUp(int mX, int mY);
    void OnExit();
    void OnLoop();
    void OnRender();
    void OnCleanup();
    
};


#endif /* CApp_h */
