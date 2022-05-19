//
//  CSurface.cpp
//  test_SDL
//
//  Created by MissBidule on 30/12/2021.
//

#include "CSurface.hpp"

CSurface::CSurface(){
    
}

SDL_Surface* CSurface::OnLoad(char* File, bool transparency){
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
    SDL_PixelFormat *format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

    
    if ((Surf_Temp = IMG_Load(File))==NULL) {
        return NULL;
    }
    
    if (!transparency) {
        Surf_Return = SDL_ConvertSurface(Surf_Temp,format,0 );
        SDL_FreeSurface(Surf_Temp);
    }
    else {
        Surf_Return = SDL_ConvertSurface(Surf_Temp,format,0 );
        SDL_FreeSurface(Surf_Temp);
    }
    
    return Surf_Return;
    
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if ((Surf_Dest == NULL) || (Surf_Src == NULL)) {
        return false;
    }
    
    SDL_Rect DestR;
    
    DestR.x = X;
    DestR.y = Y;
    
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
    
    return true;
}


bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    if ((Surf_Dest == NULL) || (Surf_Src == NULL)) {
        return false;
    }
    
    SDL_Rect DestR;
    
    DestR.x = X;
    DestR.y = Y;
    
    SDL_Rect SrcR;
    
    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;
    
    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

    return true;
}

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if (Surf_Dest == NULL) {
        return false;
    }
    
   // SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));
    
    return true;
}
