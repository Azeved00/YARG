#include "./shared.cpp"
#include <string>

void InitiateGraphics(){
    InitWindow( screenWidth, screenHeight, "Some Racing Game");
}

void DrawTimer(double time){
    int seconds = (int) time;
    int micro = -(int) round((seconds - time)*100);
    std::string s = std::to_string(seconds) + ":" + std::to_string(micro);
    DrawText(s.c_str(), 10,50,20,GRAY);
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


