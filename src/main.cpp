#include "./shared.cpp"
#include "./graphics.cpp"

// TODO: change back to Logo
State state = MainMenu;
int framesCounter = 0;
Car* player = new Car(screenWidth*0.5,screenHeight*0.8,YELLOW);

void Update(){
    switch(state)
    {
        case Logo:
            // TODO: Update LOGO screen variables here!
            
            // Wait for 2 seconds (120 frames) before jumping to TITLE screen
            framesCounter++;
            if(framesCounter == 120)
                state = MainMenu;
            break;
        
        case MainMenu:
            // TODO: Update TITLE screen variables here!

            // Press enter to change to GAMEPLAY screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                state = GamePlay;
            break;
        
        case GamePlay:
            // TODO: Update GAMEPLAY screen variables here!
            
            if (IsKeyDown(KEY_A))
                player->posX -= screenWidth*0.02;

            if (IsKeyDown(KEY_D))
                player->posX += screenWidth*0.02;

            break;
        case Lost:
            // TODO: Update ENDING screen variables here!

            // Press enter to return to TITLE screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                state = MainMenu;
            break;
        
        default: 
            break;
    }
}

void Draw(){
    switch(state)
    {
        case Logo:
            // TODO: Draw LOGO screen here!
            DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
            DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

            break;
        
        case MainMenu:
            // TODO: Draw TITLE screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
            DrawText("MENU SCREEN", 20, 20, 40, DARKGREEN);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

            break;
        
        case GamePlay:
            DrawRoad();
            player->Draw();
            break;
        
        case Lost:
        
            // TODO: Draw ENDING screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

            break;
        
        default: 
            break;
    }
}

int main(void)
{
    SetTargetFPS(targetFPS);
    InitiateGraphics();

    while (!WindowShouldClose())
    {
        Update();
        
        BeginDrawing();
      
        Draw();
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}


