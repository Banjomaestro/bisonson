//
//  CSurface.hpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#ifndef CSurface_hpp
#define CSurface_hpp

#include <stdio.h>
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

class CSurface {
    
public:
    CSurface();
    
public:
    static void drawTexture(GLuint texture, float x, float y, float w, float h, float scale);
    static void drawTexture(GLuint texture, float x, float y, float x2, float y2, float w_tex, float h_tex, float w, float h, float scale);
};

#endif /* CSurface_hpp */
