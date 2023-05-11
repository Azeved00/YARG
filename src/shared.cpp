#ifndef SHARED_CPP
#define SHARED_CPP

#include "raylib.h"


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
                this->posX - screenWidth*0.06, 
                this->posY - screenHeight*0.1,
                screenWidth*0.12,
                screenHeight*0.20,
                this->color);
        }
};

#endif
