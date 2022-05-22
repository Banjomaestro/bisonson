//
//  CArea.hpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef CArea_hpp
#define CArea_hpp

#include <stdio.h>
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
#include "CMap.hpp"
#include "CCamera.hpp"

class CArea {
    
public:
    static CArea AreaControl;
    
public:
    std::vector<CMap>   MapList;
    
private:
    int AreaSize;
    SDL_Surface* Surf_Tileset;
    GLuint ID_Tileset;
    
public:
    CArea();
    bool OnLoad(char* File, char* Abs_path);
    void OnRender();
    void OnCleanup();
    
public:
    CMap* GetMap(int X, int Y);
    CTile* GetTile(int X, int Y);
};

#endif /* CArea_hpp */
