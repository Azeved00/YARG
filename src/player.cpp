#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "./shared.cpp"
#include "./raylib.h"
#include "./graphics.cpp"

class Player : public Car 
{
public:
    Camera2D camera;
    double gameTime;

    Player() : Car( screenWidth*0.5, screenHeight*0.8, YELLOW)
    {
        this->camera = { 0 };
        camera.target = (Vector2){ (float) posX, (float) posY};
        camera.offset = (Vector2){ screenWidth/2.0f, screenHeight*0.8f };
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;

        gameTime = GetTime();
    }
    
    void Reset()
    {
        gameTime = GetTime();
        posX = screenWidth*0.5;
        posY = screenHeight*0.8;
        camera.target = (Vector2){(float) posX, (float) posY};
    }

    ~Player()
    {
        delete this;
    }

    void Update()
    {
        if (IsKeyDown(KEY_W))
            this->posY -= screenHeight*0.01;
        
        if (IsKeyDown(KEY_S))
            this->posY += screenHeight*0.01;

        if (IsKeyDown(KEY_A))
            this->posX -= screenWidth*0.01;

        if (IsKeyDown(KEY_D))
            this->posX += screenWidth*0.01;
    
        camera.target = (Vector2){ (float) this->posX, (float) this->posY };

        //gameTime = GetTime() - gameTime;
    }

    void DrawCar()
    {
        this->Draw();
    }

    void DrawHud()
    {
        DrawRectangle(0, 0, screenWidth*0.15, screenHeight*0.2, DARKGRAY);

        double time = GetTime() - gameTime;
        int seconds = (int) time;
        int micro = -(int) round((seconds - time)*100);
        std::string s = std::to_string(seconds) + ":" + std::to_string(micro);
        DrawText(s.c_str(), 10,50,20,BLACK);

        s = std::to_string(posX) + ", " + std::to_string(posY);
        DrawText(s.c_str(),10,70,20,BLACK);
    }


};


#endif
