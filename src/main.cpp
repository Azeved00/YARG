#include "./shared.cpp"
#include "./graphics.cpp"
#include "./player.cpp"
#include "./enemy.cpp"


// TODO: change back to Logo
// TODO: Find way to display logo or smth
State state = MainMenu;

void Update(){
    switch(state)
    {
        case Logo:
            state = MainMenu;
            break;
        
        case MainMenu:
            // Press enter to change to GAMEPLAY screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                state = GamePlay;
            break;
        
        case GamePlay:
            UpdatePlayer();
            UpdateEnemies();
            GenerateEnemy();
            if(CheckForCollision(player))
                state = Lost;
            break;
        case Lost:
            // Press enter to return to TITLE screen
            ResetEnemies();
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
            DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
            DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

            break;
        
        case MainMenu:
            DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
            DrawText("MENU SCREEN", 20, 20, 40, DARKGREEN);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

            break;
        
        case GamePlay:
            DrawRoad();
            player->Draw();
            DrawEnemies();
            break;
        
        case Lost:
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


