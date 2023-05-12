#include "./shared.cpp"
#include "./graphics.cpp"
#include "./player.cpp"
#include "./enemy.cpp"


// TODO: change back to Logo
// TODO: Find way to display logo or smth
State state = MainMenu;
double gameTime = 0.0f;

void StartGame(){
    ResetEnemies();
    state = GamePlay;
    gameTime = GetTime();
}

void Update(){
    switch(state)
    {
        case Logo:
            state = MainMenu;
            break;
        
        case MainMenu:
            // Press enter to change to GAMEPLAY screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                StartGame();
            break;
        
        case GamePlay:
            UpdatePlayer();
            UpdateEnemies();
            GenerateEnemy();
            if(CheckForCollision(player)){
                state = Lost;
                gameTime = GetTime() - gameTime;
            }
                
            break;

        case Lost:
            // Press enter to return to TITLE screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                StartGame();
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
            DrawTimer(GetTime()-gameTime);
            break;
        
        case Lost:
            DrawEnd(gameTime); 

            break;
        
        default: 
            break;
    }
    DrawFPS(10,10);
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


