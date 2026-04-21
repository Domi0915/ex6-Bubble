#ifndef BUBBLE_H
#define BUBBLE_H

#include "raylib.h"

class Bubble {
public:
    Bubble(Vector2 pos, float r);

    void Update();      // update position
    void Draw();
    bool IsClicked(Vector2 mousePos);

private:
    Vector2 position;   
    Vector2 velocity;  
    Color color;   
    float radius;  
    bool active;   
    double spawnTime;   // when bubble make
};

#endif
