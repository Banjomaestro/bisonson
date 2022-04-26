//
//  CMap.cpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#include "CMap.hpp"

CMap::CMap() {
    Surf_Tileset = NULL;
}

bool CMap::OnLoad(char *File) {
    TileList.clear();
    
    FILE* FileHandle = fopen(File, "r");
    
    if (FileHandle == NULL) {
        return false;
    }
    
    for (int Y = 0; Y < MAP_HEIGHT; Y++) {
        for (int X = 0; X < MAP_WIDTH; X++) {
            CTile tempTile;
            
            fscanf(FileHandle, "%d:%d", &tempTile.TileID, &tempTile.TypeID);
            
            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }
    
    fclose(FileHandle);
    
    return true;
}

void CMap::OnRender(SDL_Surface *Surf_Display, int MapX, int MapY) {
    if (Surf_Tileset == NULL) return;
    
    int TileSetWidth = Surf_Tileset->w / TILE_SIZE;
    //int TileSetHeight = Surf_Tileset->h / TILE_SIZE;
    
    int ID = 0;
    
    for (int Y = 0; Y < MAP_HEIGHT; Y++) {
        for (int X = 0; X < MAP_WIDTH; X++) {
            if (TileList[ID].TypeID == TILE_TYPE_NONE) {
                ID++;
                continue;
            }
            
            int tx = MapX + (X * TILE_SIZE);
            int ty = MapY + (Y * TILE_SIZE);
            
            int TilesetX = (TileList[ID].TileID % TileSetWidth) * TILE_SIZE;
            int TilesetY = (TileList[ID].TileID / TileSetWidth) * TILE_SIZE;
            
            CSurface::OnDraw(Surf_Display, Surf_Tileset, tx, ty, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);
            
            ID++;
        }
    }
}

CTile* CMap::GetTile(int X, int Y) {
    int ID = 0;
    
    ID = X / TILE_SIZE;
    ID = ID + (MAP_WIDTH * (Y / TILE_SIZE));
    
    if (ID < 0 || ID >= TileList.size()) return NULL;
    
    return &TileList[ID];
}
