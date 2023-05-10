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
