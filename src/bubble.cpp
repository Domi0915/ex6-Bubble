#include "bubble.h"

Bubble::Bubble(Vector2 pos, float r) 
    : position(pos), radius(r), active(true) {
    // random speed
    velocity = {(float)GetRandomValue(-3, 3), (float)GetRandomValue(-3, 3)};
    // random color
    color = Color{(unsigned char)GetRandomValue(50, 255),
                  (unsigned char)GetRandomValue(50, 255),
                  (unsigned char)GetRandomValue(50, 255),
                  255};
    spawnTime = GetTime(); // note when bubble make
}

void Bubble::Update() {
    if (active) {
        position.x += velocity.x;
        position.y += velocity.y;

        // Bounce on boundary
        if (position.x - radius < 0 || position.x + radius > GetScreenWidth()) {
            velocity.x *= -1;
        }
        if (position.y - radius < 0 || position.y + radius > GetScreenHeight()) {
            velocity.y *= -1;
        }

        // disappear after 5 second
        if (GetTime() - spawnTime > 5.0) {
            active = false;
        }
    }
}

void Bubble::Draw() {
    if (active) {
        DrawCircleV(position, radius, color);   //Draw Circle(bubble)
    }
}

bool Bubble::IsClicked(Vector2 mousePos) {
    if (active && CheckCollisionPointCircle(mousePos, position, radius)) {
        active = false;
        return true;
    }
    return false;
}

