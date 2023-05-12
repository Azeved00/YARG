#include "./shared.cpp"
#include <string>

void InitiateGraphics(){
    InitWindow( screenWidth, screenHeight, "Some Racing Game");
}

void DrawEnd(double timer){
    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
    
    int seconds = (int) timer;
    int micro = -(int) round((seconds - timer)*100);
    const char* s = (std::to_string(seconds) + ":" + std::to_string(micro)).c_str();

    int width = MeasureText(s, 50);
    DrawText(s, (screenWidth-width)*0.5,(screenHeight-50)*0.5,50,GRAY);
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


