//
//  CApp_Text.cpp
//  SDL_game
//
//  Created by MissBidule on 02/01/2022.
//

#include <stdio.h>
#include "CApp.h"

void CApp::drawText(SDL_Surface *Surf_Display, char *string, int size, short x, short y, uint8_t R, uint8_t G, uint8_t B) {
    
    char font_name[] = "font/Font.ttf";
    char font_Path[strlen(Abs_path) + strlen(font_name)];
    strcpy(font_Path, Abs_path);
    strcat(font_Path + strlen(font_Path), font_name);
    
    TTF_Font* font = TTF_OpenFont(font_Path, size);
    
    SDL_Color textColor = { R, G, B };
    
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, string, textColor);
    
    SDL_Rect textLocation = { x, y, 0, 0};
    
    SDL_BlitSurface(textSurface, NULL, Surf_Display, &textLocation);
    
    SDL_FreeSurface(textSurface);
    
    TTF_CloseFont(font);
}
