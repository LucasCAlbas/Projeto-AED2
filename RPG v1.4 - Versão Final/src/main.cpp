#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "prop.h"
#include "Enemy.h"
#include "Inventory.h"
int main(){
    //tamanho da janela do jogo
    const int windowWidth{1024};
    const int windowHeight{460};

    InitWindow(windowWidth, windowHeight, "Top Down");

    Texture2D map = LoadTexture("sprites/test_map.png"); //Input de backgroud do jogo
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};
    //inicializacao do jogador
    Character hero{windowWidth, windowHeight};

    //inicialzacao das estatuas
    Prop statue{Vector2{800.f, 700.f}, LoadTexture("sprites/Statue.png")};

    Prop props[2]{
        Prop {Vector2{600.f, 400.f}, LoadTexture("sprites/Statue.png")},
        Prop {Vector2{400.f, 500.f}, LoadTexture("sprites/Statue.png")}
    };
    //inicializacao do inimigo
    Enemy slime{
        Vector2{},
        LoadTexture("sprites/characters/slime_idle.png"),
        LoadTexture("sprites/characters/slime_walk.png")
    };
    //criterio de attack do slime
    slime.SetTarget(&hero);
    //determina o FPS maximo
    SetTargetFPS(60);
    //variaveis da lista
    bool isInventoryOpen = false;
    int seleciona = 0;
    Lista l;

    //executa o jogo enquanto a janela esta aberta
    while (!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(WHITE);
        //posicao do mapa
        mapPos = Vector2Scale(hero.getWorldPos(), -1.f);

        //Desenha o mapa
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        statue.Render(hero.getWorldPos());

    if (isInventoryOpen == false){

        hero.tick(GetFrameTime());

        slime.tick(GetFrameTime());
    }

        //objetos dentro da lista
        cria(&l);
        insere(&l, 24, 4, "Cura 5 HP", "Pocao Forte");
        insere(&l, 217, 2, "Cura 2 HP", "Carne");
        insere(&l, 836, 999, "Suspeito...", "Ram Ranch");
        insere(&l, 826, 1, "Come in", "Fulcrum");


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

        //lista


        //abre o inventario
        if (IsKeyPressed(KEY_I)){
            isInventoryOpen = !isInventoryOpen;
            }

            if (isInventoryOpen == true){
            ClearBackground(WHITE);
            janelaMenu(&seleciona, l);


        }

        if(IsKeyDown(KEY_J)){

            if(CheckCollisionRecs(slime.GetCollisionRec(), hero.GetCollisionRec()))
                slime.setAlive(false);
        }

        EndDrawing();

    }
    CloseWindow();


}
