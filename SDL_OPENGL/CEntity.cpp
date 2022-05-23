//
//  CEntity.cpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//
#include "CEntity.hpp"

std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity() {
    Surf_Entity = NULL;
    
    X = Y = 0.0f;
    Width = Height = 0;

    JumpFactor = 0;
    
    MoveLeft = MoveRight = false;
    Type = ENTITY_TYPE_GENERIC;
    Dead = false;
    Flags = ENTITY_FLAG_GRAVITY;
    
    SpeedX = SpeedY = 0;
    AccelX = AccelY = 0;
    MaxSpeedX = 10;
    MaxSpeedY = 10;
    
    CurrentFrameCol = 0;
    CurrentFrameRow = 0;
    
    Col_Width_L = Col_Width_R = 0;
    Col_Height_T = Col_Height_B = 0;
    
    CanJump = false;
}

CEntity::~CEntity() {
    
}

bool CEntity::OnLoad(char* infoFile, int playerNum) {
    
    
    FILE* FileHandle = fopen(infoFile, "r");
    
    if (FileHandle == NULL) {
        return false;
    }
    char File[15];
    int MaxFrames = 0;

    char c;
    int lines = 0;

    while (lines < playerNum){
        
        c = fgetc(FileHandle);

        if(c=='\n')
         lines++;
    } 
    
    fscanf(FileHandle, "%s %d %d %d %f", File, &Width, &Height, &MaxFrames, &JumpFactor);

    Surf_Entity = IMG_Load(File);
    
    glGenTextures(1, &ID_Entity);
    glBindTexture(GL_TEXTURE_2D, ID_Entity);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, Surf_Entity->w, Surf_Entity->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Surf_Entity->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    MaxSpeedY += JumpFactor;
    
    Anim_Control.MaxFrames = MaxFrames;
    
    return true;
}

void CEntity::OnLoop() {
    //We're not moving
    if (MoveLeft == false && MoveRight == false) {
        StopMove();
    }
    
    if (MoveLeft) {
        AccelX = -0.5;
    }
    else if (MoveRight) {
        AccelX = 0.5;
    }
    
    if (Flags & ENTITY_FLAG_GRAVITY) {
        AccelY = -0.75f;
    }
    
    SpeedX += AccelX * CFPS::FPSControl.GetSpeedFactor();
    SpeedY += AccelY * CFPS::FPSControl.GetSpeedFactor();
    
    if (SpeedX > MaxSpeedX) SpeedX = MaxSpeedX;
    if (SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
    if (SpeedY > MaxSpeedY) SpeedY = MaxSpeedY;
    if (SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;
    
    OnAnimate();
    OnMove(SpeedX, SpeedY);
}

void CEntity::OnRender() {
    if (Surf_Entity == NULL) return;
    
    CSurface::drawTexture(ID_Entity, X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, CurrentFrameCol * Width + Width-1, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height + Height-1, Surf_Entity->w, Surf_Entity->h, Width, Height, 1);
}

void CEntity::OnCleanup() {
    if (Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }
    glDeleteTextures(1, &ID_Entity);
    
    Surf_Entity = NULL;
}

void CEntity::OnAnimate() {
    if (MoveLeft) {
        CurrentFrameCol = 0;
    }
    else if (MoveRight) {
        CurrentFrameCol = 1;
    }
    
    Anim_Control.OnAnimate();
}

bool CEntity::OnCollision(CEntity *Entity) {
    return false;
}

void CEntity::OnMove(float MoveX, float MoveY) {
    CanJump = false;
    
    if (MoveX == 0 && MoveY == 0) return;
    
    double NewX = 0;
    double NewY = 0;
    
    MoveX *= CFPS::FPSControl.GetSpeedFactor();
    MoveY *= CFPS::FPSControl.GetSpeedFactor();
    
    if (MoveX != 0) {
        if (MoveX >=0) NewX = CFPS::FPSControl.GetSpeedFactor();
        else NewX = -CFPS::FPSControl.GetSpeedFactor();
    }
    
    if (MoveY != 0) {
        if (MoveY >=0) NewY = CFPS::FPSControl.GetSpeedFactor();
        else NewY = -CFPS::FPSControl.GetSpeedFactor();
    }
    
    while (true) {
        if (Flags & ENTITY_FLAG_GHOST) {
            PosValid((int) (X + NewX), (int) (Y + NewY));
            
            X += NewX;
            Y += NewY;
        }
        else {
            if (PosValid((int) (X + NewX), (int) (Y))) {
                X += NewX;
            }
            else {
                SpeedX = 0;
            }
            
            if (PosValid((int) (X), (int) (Y + NewY))) {
                Y += NewY;
            }
            else {
                if (MoveY < 0) {
                    CanJump = true;
                }
                SpeedY = 0;
            }
        }
        
        MoveX += -NewX;
        MoveY += -NewY;
        
        if (NewX > 0 && MoveX <= 0) NewX = 0;
        if (NewX < 0 && MoveX >= 0) NewX = 0;
        
        if (NewY > 0 && MoveY <= 0) NewY = 0;
        if (NewY < 0 && MoveY >= 0) NewY = 0;
        
        if (MoveX == 0) NewX = 0;
        if (MoveY == 0) NewY = 0;
        
        if (MoveX == 0 && MoveY ==0) break;
        if (NewX == 0 && NewY == 0) break;
    }
}

void CEntity::StopMove() {
    if (SpeedX > 0) {
        AccelX = -1;
    }
    
    if (SpeedX < 0) {
        AccelX = 1;
    }
    
    if (SpeedX < 2.0f && SpeedX > -2.0f) {
        AccelX = 0;
        SpeedX = 0;
    }
}

bool CEntity::Jump() {
    if (!CanJump) return false;
    
    SpeedY = MaxSpeedY+JumpFactor;
    
    return true;
}

bool CEntity::Collides(int oX, int oY, int oX2, int oY2) {
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    int tX = (int)X - Col_Width_L;
    int tY = (int)Y + Col_Height_T;
    
    left1 = tX;
    left2 = oX;
    
    right1 = (int)X + Col_Width_R;
    right2 = oX2;
    
    top1 = tY;
    top2 = oY;
    
    bottom1 = (int)Y - Col_Height_B;
    bottom2 = oY2;
    
    if (bottom1 > top2) return false;
    if (top1 < bottom2) return false;
    
    if (right1 < left2) return false;
    if (left1 > right2) return false;
    
    return true;
}

bool CEntity::PosValid(int NewX, int NewY) {
    bool Return = true;
    
    int StartX = (NewX - Col_Width_L) / TILE_SIZE;
    int StartY = (NewY - Col_Height_B) / TILE_SIZE;
    
    int EndX = (NewX + Col_Width_R) / TILE_SIZE;
    int EndY = (NewY + Col_Height_T) / TILE_SIZE;
    
    for (int iY = StartY; iY <= EndY; iY++) {
        for (int iX = StartX; iX <= EndX; iX++) {
            CTile* Tile = CArea::AreaControl.GetTile(iX * TILE_SIZE, iY * TILE_SIZE);
            if (!PosValidTile(Tile)) Return = false;
        }
    }
    
    if (Flags ^ ENTITY_FLAG_MAPONLY) {
        for (int i = 0; i < EntityList.size(); i++) {
            if (!PosValidEntity(EntityList[i], NewX, NewY)) Return = false;
        }
    }
    
    return Return;
}

bool CEntity::PosValidTile(CTile *Tile) {
    if (Tile == NULL) return true;
    
    if (Tile->TypeID == TILE_TYPE_BLOCK) return false;
    
    return true;
}

bool CEntity::PosValidEntity(CEntity* Entity, int NewX, int NewY) {
    if (((((this != Entity) && (Entity != NULL)) && !Entity->Dead) && Entity->Flags ^ ENTITY_FLAG_MAPONLY) && Entity->Collides(NewX - Col_Width_L, NewY + Col_Height_T, NewX + Col_Width_R, NewY - Col_Height_B)) {
        
        CEntityCol EntityCol;
        EntityCol.EntityA = this;
        EntityCol.EntityB = Entity;
        
        CEntityCol::EntityColList.push_back(EntityCol);
        
        return false;
    }
    
    return true;
}
