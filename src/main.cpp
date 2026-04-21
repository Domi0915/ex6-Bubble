#include "raylib.h"
#include "bubble.h"
#include <vector>

using namespace std;

int main() {
    //initialization window
    InitWindow(800, 450, "Raylib OOP");
    SetTargetFPS(60);  //update frequency

    vector<Bubble> bubbles; // all bubbles
    int score = 0;

    //window do not close
    while (!WindowShouldClose()) {
        // make bubble random
        if (GetRandomValue(0, 30) == 0) {
            Vector2 pos = {(float)GetRandomValue(50, 750), (float)GetRandomValue(50, 400)};
            bubbles.emplace_back(pos, 20.0f);
        }

        // left button check
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();   //Get mouse position
            for (auto &bubble : bubbles) {
                if (bubble.IsClicked(mousePos)) {
                    score += 1;
                }
            }
        }

        // update bubbles position
        for (auto &bubble : bubbles) {
            bubble.Update();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        //draw bubbles
        for (auto &bubble : bubbles) {
            bubble.Draw();
        }

        //show score
        DrawText(TextFormat("Score: %d", score), 10, 10, 20, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

