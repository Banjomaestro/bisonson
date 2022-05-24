//
//  CEntity.hpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef CEntity_hpp
#define CEntity_hpp

#include <stdio.h>
#include <vector>
#include "CArea.hpp"
#include "CAnimation.hpp"
#include "CCamera.hpp"
#include "CFPS.hpp"
#include "CSurface.hpp"
#include <SFML/Audio.hpp>

enum {
    ENTITY_TYPE_GENERIC = 0,
    ENTITY_TYPE_PLAYER
};

enum {
    ENTITY_FLAG_NONE = 0,
    ENTITY_FLAG_GRAVITY = 0x00000001,
    ENTITY_FLAG_GHOST = 0x00000002,
    ENTITY_FLAG_MAPONLY = 0x00000004
};

class CEntity {

public:
    static std::vector<CEntity*> EntityList;
    
protected:
    CAnimation Anim_Control;
    SDL_Surface* Surf_Entity;
    GLuint ID_Entity;
    sf::SoundBuffer jumpBuffer;
    sf::Sound jumpSound;

    
public:
    float X;
    float Y;
    
    int Width;
    int Height;
    
    bool MoveLeft;
    bool MoveRight;
    
public:
    int Type;
    
    bool Dead;
    int Flags;
    
protected:
    float SpeedX;
    float SpeedY;
    
    float AccelX;
    float AccelY;
    
public:
    float MaxSpeedX;
    float MaxSpeedY;

    float JumpFactor;

    float YAccelerator;
    
protected:
    int CurrentFrameCol;
    int CurrentFrameRow;
    
protected:
    int Col_Width_L;
    int Col_Width_R;
    int Col_Height_T;
    int Col_Height_B;
    
protected:
    bool CanJump;
    
public:
    CEntity();
    virtual ~CEntity();
    
public:
    virtual bool OnLoad(char* File, int playerNum);
    virtual void OnLoop();
    virtual void OnRender();
    virtual void OnCleanup();
    virtual void OnAnimate();
    virtual bool OnCollision(CEntity* Entity);
    
public:
    void OnMove(float MoveX, float MoveY);
    void StopMove();
    bool Jump();
    
public:
    bool Collides(int oX, int oY, int oX2, int oY2);
    
private:
    bool PosValid(int NewX, int NewY);
    bool PosValidTile(CTile* Tile);
    bool PosValidEntity(CEntity* Entity, int NewX, int NewY);
};

class CEntityCol {
    
public:
    static std::vector<CEntityCol> EntityColList;
    
public:
    CEntity* EntityA;
    CEntity* EntityB;
    
public:
    CEntityCol();
};
#endif /* CEntity_hpp */
