#include <vector>
#include <math.h>
#include "./shared.cpp"

double spawnRate = 25;
static const double maxSpawnRate = 1000;

// 0 to 3, center point of each lane from left to right
std::vector<int> lanes = { (int) round(screenWidth*0.21), 
                           (int) round(screenWidth*0.40),
                           (int) round(screenWidth*0.60),
                           (int) round(screenWidth*0.79)};

std::vector<Car*> enemies = {};

void DrawEnemies(){
    for(Car* c : enemies){
        c->Draw();
    }
}

void GenerateEnemy(){
    int chance = GetRandomValue(0,maxSpawnRate);
    if(chance > spawnRate) 
        return;

    int lane = GetRandomValue(0,3);

    Car* c = new Car(lanes[lane],0,BLUE);
    c->direction = (lane < 2) * 2 +1;

    enemies.push_back(c);
}

void UpdateEnemies(){
    for (auto it = enemies.begin(); it != enemies.end(); it++) {
        Car* c = *it;
        c->posY += c->speed * c->direction;
        
        if(c->posY < 0){
            it = enemies.erase(it); // erase the current element and get the iterator to the next element
            it--;
        }
    }
}

bool CheckForCollision(Car* car){
    for(Car* c : enemies){
        if(c->IsColliding(car))
            return true;
    }
    return false;
}

void ResetEnemies(){
    enemies.clear();
}

