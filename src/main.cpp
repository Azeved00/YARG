#include "raylib.h"

typedef enum State {
    GamePlay,
    Lost,
    Pause,
    MainMenu,
    Settings,
    Logo
} State;


static const int screenHeight = 450;
static const int screenWidth = 800;
static const int targetFPS = 60;

// TODO: change back to Logo
State state = MainMenu;
int framesCounter = 0;

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
                
                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                    state = Lost;
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
                
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

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
    InitWindow( screenWidth, screenHeight, "Some Racing Game");
    SetTargetFPS(targetFPS);

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


