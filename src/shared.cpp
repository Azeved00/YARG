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
    public: 
        Color color;
        Rectangle hitbox;
        Vector2 speed;
        Vector2 aceleration;

        Car(int posX, int posY, Color color, Vector2 speed)
        {
            this->hitbox = {(float) posX, (float) posY, screenWidth*0.12, screenHeight*0.20};
            this->color = color;
            this->speed = speed;
            this->aceleration = (Vector2){0,0};
        }

        void Update(){
            hitbox.x += speed.x;
            hitbox.y += speed.y;
        }

        void Draw()
        {
            DrawRectangleRec( hitbox, this->color);
            /*DrawRectanglePro(
                    hitbox,
                    {},
                    0,
                this->color);*/
            //DrawText(std::to_string(speed).c_str(),this->posX,this->posY,10,BLACK);
        }

        bool IsColliding(Car* c)
        {
            return CheckCollisionRecs(this->hitbox,c->hitbox); 
        }
};

#endif
