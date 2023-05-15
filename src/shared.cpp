#ifndef SHARED_CPP
#define SHARED_CPP

#include "raylib.h"
#include "math.h"
#include <string>

static const int screenHeight = 450;
static const int screenWidth = 800;

static const int targetFPS = 60;


typedef enum State {
    GamePlay,
    Lost,
    Won,
    Pause,
    MainMenu,
    Settings,
    Logo
} State;

class Car{
    static const Vector2 size;
    
    public: 
        Color color;
        Vector2 position;
        Vector2 speed;
        Vector2 aceleration;

        Car(int posX, int posY, Color color, Vector2 speed)
        {
            this->position = (Vector2){(float) posX, (float) posY};
            this->color = color;
            this->speed = speed;
            this->aceleration = (Vector2){0,0};
        }

        void Update(){
            position.x += speed.x;
            position.y += speed.y;
        }

        Car(int posX, int posY, Color color)
        {
            this->position = (Vector2){(float) posX, (float) posY};
            this->color = color;
            this->speed = (Vector2){4,0};
            this->aceleration = (Vector2){0,0};
        }

        void Draw()
        {
            DrawRectangle(
                this->position.x - screenWidth*size.x*0.5, 
                this->position.y - screenHeight*size.y*0.5,
                screenWidth*size.x,
                screenHeight*size.y,
                this->color);
            //DrawText(std::to_string(speed).c_str(),this->posX,this->posY,10,BLACK);
        }

        bool IsColliding(Car* c)
        {
            int offsetX = (int) round(screenWidth*size.x*0.5);
            int offsetY = (int) round(screenHeight*size.y*0.5);
        
            int left1 = this->position.x - offsetX,
                right1 = this->position.x + offsetX,
                top1 = this->position.y + offsetY,
                bottom1 = this->position.y - offsetY;
            
            int left2 = c->position.x - offsetX,
                right2 = c->position.x + offsetX,
                top2 = c->position.y + offsetY,
                bottom2 = c->position.y - offsetY;

            bool res = false;
            res |= left1 < left2 &&  left2 < right1 &&  bottom1 < top2 && top2 < top1;
            res |= left1 < right2 &&  right2 < right1 &&  bottom1 < top2 && top2 < top1;
 
            res |= left1 < left2 &&  left2 < right1 &&  bottom1 < bottom2 && bottom2 < top1;
            res |= left1 < right2 &&  right2 < right1 &&  bottom1 < bottom2 && bottom2 < top1;
            return res; 
        }
};

const Vector2 Car::size = (Vector2) {0.12,0.20};

#endif
