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
#include "Define.h"

class CApp : public CEvent {
    
private:
    char * Abs_path;
    bool Running;
    SDL_Window* Surf_Display;
    SDL_Surface* tabSurf[11];
    GLuint IDtext[11];
    SDL_GLContext context;
    Uint32 startTime;
    
private:
    time_t rawtime;
    struct tm* timeinfo;
    int heures;
    int minutes;
    int secondes;
    
//private:
//    CPlayer Player;
//    CPlayer Player2;
    
public:
    CApp(char * path);
    void onWindowResized(unsigned int width, unsigned int height);
    int OnExecute();
    
public:
    bool OnInit();
//    void drawText(SDL_Surface* Surf_Display, char* string, int size, short x, short y, uint8_t R, uint8_t G, uint8_t B);
    void OnEvent(SDL_Event* Event);
    void OnKeyDown(SDL_Keycode sym);
    void OnKeyUp(SDL_Keycode sym);
    void OnExit();
    void OnLoop();
    void OnRender();
    void OnCleanup();
    
};


#endif /* CApp_h */
