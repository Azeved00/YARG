#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "./shared.cpp"
#include "./raylib.h"

class Player 
{
public:
    Car* car;
    Camera2D camera;

    Player()
    {
        int width = screenWidth*0.5;
        int height = screenHeight*0.8;
        this->car = new Car(width,height,YELLOW);

        this->camera = { 0 };
        camera.target = (Vector2){ (float) width, (float) height };
        camera.offset = (Vector2){ screenWidth/2.0f, screenHeight*0.8f };
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;
    }

    ~Player()
    {
        delete this->car;
    }

    void Update()
    {
        if (IsKeyDown(KEY_W))
            this->car->posY -= screenHeight*0.01;
        
        if (IsKeyDown(KEY_S))
            this->car->posY += screenHeight*0.01;

        if (IsKeyDown(KEY_A))
            this->car->posX -= screenWidth*0.01;

        if (IsKeyDown(KEY_D))
            this->car->posX += screenWidth*0.01;
    
        camera.target = (Vector2){ (float) this->car->posX, (float) this->car->posY };
    }

    void Draw()
    {
        this->car->Draw();
    }
};


#endif
