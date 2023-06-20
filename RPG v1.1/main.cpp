#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main(){

    const int windowWidth{1024};
    const int windowHeight{460};

    InitWindow(windowWidth, windowHeight, "Top Down");

    Texture2D map = LoadTexture("sprites/test_map.png"); //Input de backgroud do jogo
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character hero{windowWidth, windowHeight};

    SetTargetFPS(60);

    while (!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(hero.getWorldPos(), -1.f);

        //Desenha o mapa
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        hero.tick(GetFrameTime());

        //Colisao entre a tela e os cantos do mapa
        if (hero.getWorldPos().x < 0.f ||
            hero.getWorldPos().y < 0.f ||
            hero.getWorldPos().x + windowWidth > map.width * mapScale||
            hero.getWorldPos().y + windowHeight > map.height * mapScale)
            {
                hero.undoMovement();
            }

        EndDrawing();

    }
    CloseWindow();


}
