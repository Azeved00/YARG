#include "./shared.cpp"
#include "./graphics.cpp"
#include "./player.cpp"
#include "./enemy.cpp"


// TODO: change back to Logo
// TODO: Find way to display logo or smth
State state = MainMenu;
Player* player = new Player();

void StartGame()
{
    ResetEnemies();
    state = GamePlay;
    player->Reset();
}

bool ReachedFinish(Player* p)
{
    return p->position.y < -screenHeight*4 -200;
}

void Update()
{
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
            player->Update();
            UpdateEnemies();
            GenerateEnemy();
            if(CheckForCollision(player))
            {
                state = Lost;
            }
            if(ReachedFinish(player))
                state = Won;
            if(IsKeyPressed(KEY_P))
            {
                state = Pause;
            }
            break;

        case Lost:
            // Press enter to return to TITLE screen
            if (IsKeyPressed(KEY_ENTER))
                StartGame();
            break;
        
        case Pause:
            if(IsKeyPressed(KEY_P))
                state = GamePlay;
            if(IsKeyPressed(KEY_ENTER))
                state = Lost;
            break;

        default: 
            break;
    }
}

void Draw()
{
    ClearBackground(GREEN);
    
    BeginDrawing();
    
    //draw things not in screen
    BeginMode2D(player->camera);
        switch(state)
        {
            case GamePlay:
                DrawRoad();
                player->DrawCar();
                DrawEnemies();
                break;

            default:
                break;
        }
    EndMode2D();

    //draw things allways in scren;
    switch(state)
    {
        case Logo:
            DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);

            break;
        
        case MainMenu:
            DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
            DrawText("MENU SCREEN", 20, 20, 40, DARKGREEN);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, screenHeight-30, 20, DARKGREEN);

            break;
        
        case GamePlay:
            player->DrawHud();
            break;

        case Lost:
            DrawEnd(player->gameTime); 
            break;

        case Won:
            DrawWon(player->gameTime);
            break;

        case Pause:
            DrawRectangle(0, 0, screenWidth, screenHeight, GOLD);
            DrawText("PAUSE SCREEN", 20, 20, 40, ORANGE);
            DrawText("PRESS P too GAMEPLAY SCREEN", 120, screenHeight-30, 20, ORANGE);
            DrawText("PRESS ENTER too GAMEPLAY SCREEN", 120, screenHeight-60, 20, ORANGE);
            break;
        
        case Settings:
            break;
    }
    DrawFPS(10,10);
    EndDrawing();
}

int main(void)
{
    SetTargetFPS(targetFPS);
    InitiateGraphics();
    
    while (!WindowShouldClose())
    {
        Update();
        Draw();            
    }

    CloseWindow();

    return 0;
}


