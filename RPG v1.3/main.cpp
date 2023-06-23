#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "prop.h"
#include "Enemy.h"

int main(){

    const int windowWidth{1024};
    const int windowHeight{460};

    InitWindow(windowWidth, windowHeight, "Top Down");

    Texture2D map = LoadTexture("sprites/test_map.png"); //Input de backgroud do jogo
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character hero{windowWidth, windowHeight};


    Prop statue{Vector2{800.f, 700.f}, LoadTexture("sprites/Statue.png")};

    Prop props[2]{
        Prop {Vector2{600.f, 400.f}, LoadTexture("sprites/Statue.png")},
        Prop {Vector2{400.f, 500.f}, LoadTexture("sprites/Statue.png")}
    };

    Enemy slime{
        Vector2{},
        LoadTexture("sprites/characters/slime_idle.png"),
        LoadTexture("sprites/characters/slime_walk.png")
    };

    slime.SetTarget(&hero);

    SetTargetFPS(60);

    while (!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(hero.getWorldPos(), -1.f);

        //Desenha o mapa
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        statue.Render(hero.getWorldPos());

        hero.tick(GetFrameTime());

        //Desenha objetos
        for (auto prop : props){

            prop.Render(hero.getWorldPos());
            }

        //Colisao entre a tela e os cantos do mapa
        if (hero.getWorldPos().x < 0.f ||
            hero.getWorldPos().y < 0.f ||
            hero.getWorldPos().x + windowWidth > map.width * mapScale||
            hero.getWorldPos().y + windowHeight > map.height * mapScale)
            {
                hero.undoMovement();
            }
        //Colisao entre o personagem e objetos
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.GetCollisionRec(hero.getWorldPos()), hero.GetCollisionRec()))
            {
                hero.undoMovement();
            }
        }

        slime.tick(GetFrameTime());

        EndDrawing();

    }
    CloseWindow();


}
