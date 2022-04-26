//
//  CArea.cpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#include "CArea.hpp"

CArea CArea::AreaControl;

CArea::CArea() {
    AreaSize = 0;
}

bool CArea::OnLoad(char* File, char* Abs_path) {
    MapList.clear();
    
    char area_file[strlen(Abs_path) + strlen(File)];
    strcpy(area_file, Abs_path);
    strcat(area_file + strlen(area_file), File);
    
    FILE* FileHandle = fopen(area_file, "r");
    
    if (FileHandle == NULL) {
        return false;
    }
    
    char TilesetPath[255];
    char TilesetFile[255];
    strcpy(TilesetFile, Abs_path);
    
    fscanf(FileHandle, "%s\n", TilesetPath);
    
    strcat(TilesetFile + strlen(TilesetFile), TilesetPath);
    
    if (!(Surf_Tileset = CSurface::OnLoad(TilesetFile))) {
        fclose(FileHandle);
        return false;
    }
    
    fscanf(FileHandle, "%d\n", &AreaSize);
    
    for (int Y = 0; Y < AreaSize; Y++) {
        for (int X = 0; X < AreaSize; X++) {
            char MapPath[255];
            char MapFile[255];
            strcpy(MapFile, Abs_path);
            
            fscanf(FileHandle, "%s", MapPath);
            
            strcat(MapFile + strlen(MapFile), MapPath);
            
            CMap tempMap;
            if (tempMap.OnLoad(MapFile) == false) {
                fclose(FileHandle);
                return false;
            }
            
            tempMap.Surf_Tileset = Surf_Tileset;
            
            MapList.push_back(tempMap);
        }
        fscanf(FileHandle, "\n");
    }
    fclose(FileHandle);
    
    return true;
    
}

void CArea::OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY) {
    int MapWidth = MAP_WIDTH * TILE_SIZE;
    int MapHeight = MAP_HEIGHT * TILE_SIZE;
    
    int FirstID = -CameraX / MapWidth;
    FirstID = FirstID + ((-CameraY / MapHeight) * AreaSize);
    
    for (int i = 0; i < 4; i++) {
        int ID = FirstID + ((i / 2) * AreaSize) + (i%2);
        
        if (ID < 0 || ID >= MapList.size()) continue;
        
        int X = ((ID % AreaSize) * MapWidth) + CameraX;
        int Y = ((ID / AreaSize) * MapHeight) + CameraY;
        
        MapList[ID].OnRender(Surf_Display, X, Y);
    }
}

void CArea::OnCleanup() {
    if (Surf_Tileset) {
        SDL_FreeSurface(Surf_Tileset);
    }
    
    MapList.clear();
}

CMap* CArea::GetMap(int X, int Y) {
    int MapWidth = MAP_WIDTH * TILE_SIZE;
    int MapHeight = MAP_HEIGHT * TILE_SIZE;
    
    int ID = X / MapWidth;
    ID = ID + ((Y / MapHeight) * AreaSize);
    
    if (ID < 0 || ID >= MapList.size()) {
        return NULL;
    }
    
    return  &MapList[ID];
}

CTile* CArea::GetTile(int X, int Y) {
    int MapWidth = MAP_WIDTH * TILE_SIZE;
    int MapHeight = MAP_HEIGHT * TILE_SIZE;
    
    CMap* Map = GetMap(X, Y);
    
    if (Map == NULL) return NULL;
    
    X = X%MapWidth;
    Y = Y%MapHeight;
    
    return Map->GetTile(X, Y);
}
