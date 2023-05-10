#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "./shared.cpp"

Car* player = new Car(screenWidth*0.5,screenHeight*0.8,YELLOW);

void UpdatePlayer(){
    if (IsKeyDown(KEY_A))
        player->posX -= screenWidth*0.01;

    if (IsKeyDown(KEY_D))
        player->posX += screenWidth*0.01;

}

#endif
