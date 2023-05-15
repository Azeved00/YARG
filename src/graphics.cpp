#ifndef GRAPHICS_CPP
#define GRAPHICS_CPP
#include "./shared.cpp"
#include <string>

Image roadImage;
Texture roadTexture;

void InitiateGraphics()
{
    InitWindow( screenWidth, screenHeight, "Some Racing Game");
    
    roadImage = LoadImage("./assets/road.png");
    if(!IsImageReady(roadImage)){
        printf("Image ../assets/road.png is not ready\n");
        return;
    }

    roadTexture = LoadTextureFromImage(roadImage);
}

void DrawEnd(double timer)
{
    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, screenHeight-30, 20, DARKBLUE);
    
    int seconds = (int) timer;
    int micro = -(int) round((seconds - timer)*100);
    const char* s = (std::to_string(seconds) + ":" + std::to_string(micro)).c_str();

    int width = MeasureText(s, 50);
    DrawText(s, (screenWidth-width)*0.5,(screenHeight-50)*0.5,50,GRAY);
}

void DrawWon(double timer)
{
    DrawRectangle(0, 0, screenWidth, screenHeight,VIOLET);
    DrawText("WINNING SCREEN", 20, 20, 40,PURPLE);
    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, screenHeight-30, 20,PURPLE);
    
    int seconds = (int) timer;
    int micro = -(int) round((seconds - timer)*100);
    const char* s = (std::to_string(seconds) + ":" + std::to_string(micro)).c_str();

    int width = MeasureText(s, 50);
    DrawText(s, (screenWidth-width)*0.5,(screenHeight-50)*0.5,50, WHITE);
}

void DrawRoad()
{
    for(int i = 0; i < 5; i++)
    {
        DrawTexture(roadTexture, 0, -screenHeight*i, WHITE);
    }
}

#endif
