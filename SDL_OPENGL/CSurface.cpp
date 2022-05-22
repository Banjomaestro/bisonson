//
//  CSurface.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include "CSurface.hpp"

CSurface::CSurface(){
    
}

void CSurface::drawTexture(GLuint texture, float x, float y, float w, float h, float scale) {
    //coord x,y, size w,h, scale = 1
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();
    glTranslatef(x*scale, y*scale, 0);
    glScalef(w*scale, h*scale, 0);


    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex2f( -0.5 , 0.5);
    glTexCoord2f(1, 0);
    glVertex2f( 0.5 , 0.5);
    glTexCoord2f(1, 1);
    glVertex2f( 0.5 , -0.5);
    glTexCoord2f(0, 1);
    glVertex2f( -0.5 , -0.5);

    glEnd();

    glPopMatrix();
    //
}


void CSurface::drawTexture(GLuint texture, float x, float y, float x1, float y1, float x2, float y2, float w_tex, float h_tex, float w, float h, float scale) {
    //coord x,y, size w,h, scale = 1
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();
    glTranslatef(x*scale, y*scale, 0);
    glScalef(w*scale, h*scale, 0);


    glBegin(GL_QUADS);

    glTexCoord2f(x1/w_tex, y1/h_tex);
    glVertex2f( -0.5 , 0.5);
    glTexCoord2f(x2/w_tex, y1/h_tex);
    glVertex2f( 0.5 , 0.5);
    glTexCoord2f(x2/w_tex, y2/h_tex);
    glVertex2f( 0.5 , -0.5);
    glTexCoord2f(x1/w_tex, y2/h_tex);
    glVertex2f( -0.5 , -0.5);

    glEnd();

    glPopMatrix();
    //
}
