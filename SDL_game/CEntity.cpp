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
    
    Col_X = Col_Y = 0;
    Col_Width = Col_Height = 0;
    
    CanJump = false;
}

CEntity::~CEntity() {
    
}

bool CEntity::OnLoad(char* File, int Width, int Height, int MaxFrames, bool transparency, int R, int G, int B) {
    if ((Surf_Entity = CSurface::OnLoad(File, transparency)) == NULL) {
        return false;
    }
    
    if (transparency) {
        CSurface::Transparent(Surf_Entity, R, G, B);
    }
    
    this->Width = Width;
    this->Height = Height;
    
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
        AccelY = 0.75f;
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

void CEntity::OnRender(SDL_Surface* Surf_Display) {
    if (Surf_Entity == NULL || Surf_Display == NULL) return;
    
    CSurface::OnDraw(Surf_Display, Surf_Entity, X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, Width, Height);
}

void CEntity::OnCleanup() {
    if (Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }
    
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
                if (MoveY > 0) {
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
    
    SpeedY = -MaxSpeedY;
    
    return true;
}

bool CEntity::Collides(int oX, int oY, int oW, int oH) {
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    int tX = (int)X + Col_X;
    int tY = (int)Y + Col_Y;
    
    left1 = tX;
    left2 = oX;
    
    right1 = left1 + Width - 1 - Col_Width;
    right2 = oX + oW - 1;
    
    top1 = tY;
    top2 = oY;
    
    bottom1 = top1 + Height - 1 - Col_Height;
    bottom2 = oY + oH - 1;
    
    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;
    
    if (right1 < left2) return false;
    if (left1 > right2) return false;
    
    return true;
}

bool CEntity::PosValid(int NewX, int NewY) {
    bool Return = true;
    
    int StartX = (NewX + Col_X) / TILE_SIZE;
    int StartY = (NewY + Col_Y) / TILE_SIZE;
    
    int EndX = ((NewX + Col_X) + Width - Col_Width - 1) / TILE_SIZE;
    int EndY = ((NewY + Col_Y) + Height - Col_Height - 1) / TILE_SIZE;
    
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
    if (((((this != Entity) && (Entity != NULL)) && !Entity->Dead) && Entity->Flags ^ ENTITY_FLAG_MAPONLY) && Entity->Collides(NewX + Col_X, NewY + Col_Y, Width - Col_Width - 1, Height - Col_Height - 1)) {
        
        CEntityCol EntityCol;
        EntityCol.EntityA = this;
        EntityCol.EntityB = Entity;
        
        CEntityCol::EntityColList.push_back(EntityCol);
        
        return false;
    }
    
    return true;
}