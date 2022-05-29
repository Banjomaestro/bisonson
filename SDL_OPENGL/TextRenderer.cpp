#include "TextRenderer.hpp"

#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>
#include FT_FREETYPE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>


    FT_Face face;                 

namespace glfreetype {
    inline int next_p2 (int a )
    {
        int rval=1;
        while(rval<a) rval<<=1;
        return rval;
    }

    FT_BitmapGlyph generateBitmapForFace(FT_Face face, char ch)
    {
        if(FT_Load_Glyph( face, FT_Get_Char_Index( face, ch ), FT_LOAD_DEFAULT ))
            throw std::runtime_error("FT_Load_Glyph failed");
     
        FT_Glyph glyph;
        if(FT_Get_Glyph( face->glyph, &glyph ))
            throw std::runtime_error("FT_Get_Glyph failed");
     
        FT_Glyph_To_Bitmap( &glyph, ft_render_mode_normal, 0, 1 );
        return (FT_BitmapGlyph)glyph;
    }

    void storeTextureData(int const width, 
                          int const height,
                          FT_Bitmap & bitmap,
                          std::vector<GLubyte> & expanded_data)
    {
        for(int j = 0; j < height ; j++) {
            for(int i = 0; i < width; i++) {
                expanded_data[2 * (i + j * width) + 1] =
                (i >= bitmap.width || j >= bitmap.rows) ? 0 :
                bitmap.buffer[i + bitmap.width * j];
            }
        }
    }

    void make_dlist ( FT_Face face, char ch, GLuint list_base, GLuint * tex_base ) {
     
        FT_BitmapGlyph bitmap_glyph = generateBitmapForFace(face, ch);
     
        FT_Bitmap& bitmap=bitmap_glyph->bitmap;

        int width = next_p2( bitmap.width );
        int height = next_p2( bitmap.rows ) ;

        std::vector<GLubyte> expanded_data(2 * width * height, 0);

        storeTextureData(width, height, bitmap, expanded_data);

        glBindTexture( GL_TEXTURE_2D, tex_base[(unsigned int)ch]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
         
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
            GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, &expanded_data.front() );

        glNewList(list_base+ch,GL_COMPILE);
     
        glBindTexture(GL_TEXTURE_2D, tex_base[(unsigned int)ch]);
     
        glPushMatrix();
     
        glTranslatef(bitmap_glyph->left,0,0);
        glTranslatef(0,bitmap_glyph->top-(bitmap.rows * 0.9),0);
     
        float x = (float)bitmap.width / (float)width,
              y = (float)bitmap.rows / (float)height;
     
        glBegin(GL_QUADS);
        glTexCoord2d(0,0); glVertex2f(0,bitmap.rows);
        glTexCoord2d(0,y); glVertex2f(0,0);
        glTexCoord2d(x,y); glVertex2f(bitmap.width,0);
        glTexCoord2d(x,0); glVertex2f(bitmap.width,bitmap.rows);
        glEnd();
        glPopMatrix();

        glTranslatef(face->glyph->advance.x >> 6 ,0,0);

        glEndList();
    }

    void font_data::init(const char * fname, unsigned int h) {

        textures.resize(128);
     
        this->h=h;
     
        FT_Library library;
        if (FT_Init_FreeType( &library ))
            throw std::runtime_error("FT_Init_FreeType failed");
     
        
     
        if (FT_New_Face( library, fname, 0, &face ))
            throw std::runtime_error("FT_New_Face failed (there is probably a problem with your font file)");

        FT_Set_Char_Size( face, h * 64, h *64, 96, 96);
     
        list_base=glGenLists(128);
        glGenTextures( 128, &textures.front() );
     
        for(unsigned char i=0;i<128;i++) {
            make_dlist(face, i, list_base, &textures.front());
        }
     
        FT_Done_Face(face);
     
        FT_Done_FreeType(library);
    }

    void font_data::clean() {
        glDeleteLists(list_base,128);
        glDeleteTextures(128, &textures.front());
    }

    inline void pushScreenCoordinateMatrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(viewport[0],viewport[2],viewport[1],viewport[3]);
        glPopAttrib();
    }
     
    inline void pop_projection_matrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glPopAttrib();
    }

    void print(const int R, const int G, const int B, const font_data &ft_font, float x, float y, std::string const & text)  {
        
        glColor3ub(R,G,B);
        
        pushScreenCoordinateMatrix();                                  
             
        GLuint font=ft_font.list_base;

        float h=(ft_font.h/.63f);                                                
     
        std::stringstream ss(text);
        std::string to;
        std::vector<std::string> lines;
        while(std::getline(ss,to,'\n')){
            lines.push_back(to);
        }
  
        glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT  | GL_ENABLE_BIT | GL_TRANSFORM_BIT);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);     
     
        glListBase(font);

        float modelview_matrix[16];    
        glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
     
        for(int i=0;i<lines.size();i++) {
            glPushMatrix();
            glLoadIdentity();
            glTranslatef(x,y-h*i,0);
            glMultMatrixf(modelview_matrix);
     
            glCallLists(lines[i].length(), GL_UNSIGNED_BYTE, lines[i].c_str());
            glPopMatrix();
        }
     
        glPopAttrib();         
     
        pop_projection_matrix();
        
        glColor3ub(255,255,255);
    }
}
