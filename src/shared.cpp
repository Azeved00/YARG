#ifndef SHARED_CPP
#define SHARED_CPP

#include "raylib.h"
#include "math.h"

static const int screenHeight = 450;
static const int screenWidth = 800;

static const int targetFPS = 60;


typedef enum State {
    GamePlay,
    Lost,
    Pause,
    MainMenu,
    Settings,
    Logo
} State;

class Car{
    static const int baseSpeed = 4;
    static const double sizeX;
    static const double sizeY;
    
    public: 
        int posX;
        int posY;
        Color color;
        unsigned int speed;
        int direction;

        Car(int posX, int posY, Color color){
            this->posX = posX;
            this->posY = posY;
            this->color = color;
            this->speed = baseSpeed;
        }

        void Draw(){
            DrawRectangle(
                this->posX - screenWidth*sizeX*0.5, 
                this->posY - screenHeight*sizeY*0.5,
                screenWidth*sizeX,
                screenHeight*sizeY,
                this->color);
        }

        bool IsColliding(Car* c){
            int offsetX = (int) round(screenWidth*sizeX*0.5);
            int offsetY = (int) round(screenHeight*sizeY*0.5);
        
            int left1 = this->posX - offsetX,
                right1 = this->posX + offsetX,
                top1 = this->posY + offsetY,
                bottom1 = this->posY - offsetY;
            
            int left2 = c->posX - offsetX,
                right2 = c->posX + offsetX,
                top2 = c->posY + offsetY,
                bottom2 = c->posY - offsetY;

            bool res = false;
            res |= left1 < left2 &&  left2 < right1 &&  bottom1 < top2 && top2 < top1;
            res |= left1 < right2 &&  right2 < right1 &&  bottom1 < top2 && top2 < top1;
 
            res |= left1 < left2 &&  left2 < right1 &&  bottom1 < bottom2 && bottom2 < top1;
            res |= left1 < right2 &&  right2 < right1 &&  bottom1 < bottom2 && bottom2 < top1;
            return res; 
        }
};
const double Car::sizeX = 0.12;
const double Car::sizeY = 0.20;

#endif
