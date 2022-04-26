#pragma once
#include "CommonStruct.h"

class Square{
    
    private:
        float accelerationX;
        float accelerationY;
        
        float speedX;
        float speedY;

    public:
        float height;
        float width;
        Color color;

        Position initial;
        Position goal;
        Position current;

        float jumpPower;
        float movementSpeed;

        Square(float height, float width, Color color, Position initial, Position goal, Position current, float jumpPower, float movementSpeed);

        void jump();
        void moveRight();
        void moveLeft();
        void actualizePosition();

};


