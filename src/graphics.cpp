#include "./shared.cpp"

void InitiateGraphics(){
    InitWindow( screenWidth, screenHeight, "Some Racing Game");
}


void DrawRoad(){
    //grass
    DrawRectangle( 0, 0, screenWidth, screenHeight, GREEN);
    
    //road
    DrawRectangle( screenWidth*0.1, 0, screenWidth*0.8, screenHeight, DARKGRAY);
    
    //lines
    DrawRectangle( screenWidth*0.08, 0, screenWidth*0.02, screenHeight, WHITE);
    DrawRectangle( screenWidth*0.29, 0, screenWidth*0.01, screenHeight, WHITE);
    DrawRectangle( screenWidth*0.49, 0, screenWidth*0.02, screenHeight, WHITE);
    DrawRectangle( screenWidth*0.69, 0, screenWidth*0.01, screenHeight, WHITE);
    DrawRectangle( screenWidth*0.90, 0, screenWidth*0.02, screenHeight, WHITE);

}


