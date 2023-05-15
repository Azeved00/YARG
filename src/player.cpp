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
    Vector2 initial;

    Player() : Car( screenWidth*0.5*0.88, screenHeight*0.7, YELLOW, {0,0})
    {
        this->camera = { 0 };
        camera.target = {hitbox.x,hitbox.y};
        camera.offset = (Vector2){ screenWidth/2.0f - hitbox.width/2.0f, 
            screenHeight/2.0f - hitbox.height/2.0f };
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;

        gameTime = GetTime();

        initial = { hitbox.x, hitbox.y };
    }
    
    void Reset()
    {
        gameTime = GetTime();

        hitbox.x = initial.x;
        hitbox.y = initial.y;
        speed = {0,0};
        aceleration = {0,0};
        camera.target = {hitbox.x, hitbox.y};
    }

    ~Player()
    {
        delete this;
    }

    void Update()
    {
        if (IsKeyDown(KEY_W))
            speed.y -= 0.1;
        
        if (IsKeyDown(KEY_S))
            speed.y += 0.1;

        if (IsKeyDown(KEY_A))
            speed.x -= 0.1;

        if (IsKeyDown(KEY_D))
            speed.x += 0.1;
    
        this->hitbox.y += speed.y;
        this->hitbox.x += speed.x;
        camera.target = {hitbox.x,hitbox.y};

        //gameTime = GetTime() - gameTime;
    }

    void DrawCar()
    {
        this->Draw();
    }

    void DrawHud()
    {
        DrawRectangle(0, 0, screenWidth*0.15, 120, DARKGRAY);
        std::string s;

        double time = GetTime() - gameTime;
        int seconds = (int) time;
        int micro = -(int) round((seconds - time)*100);
        s = std::to_string(seconds) + ":" + std::to_string(micro);
        DrawText(s.c_str(), 10,50,20,BLACK);

        s = std::to_string(hitbox.x) + ", " + std::to_string(hitbox.y);
        DrawText(s.c_str(),10,70,20,BLACK);

        s = std::to_string(speed.x) + ", " + std::to_string(speed.y) ;
        DrawText(s.c_str(),10,90,20,BLACK);
    }

};


#endif
