#include "raylib.h"
#include "raymath.h"

class Character{

public:
    Vector2 getWorldPos(){ return worldPos; }
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);
private:
    Texture2D texture = LoadTexture("sprites/characters/player_idle_f.png");
    Texture2D idle_f = LoadTexture("sprites/characters/player_idle_f.png");
    Texture2D run_f = LoadTexture("sprites/characters/player_run_f.png");
    Texture2D idle_s = LoadTexture("sprites/characters/player_idle_s.png");
    Texture2D run_s = LoadTexture("sprites/characters/player_run_s.png");
    Texture2D idle_b = LoadTexture("sprites/characters/player_idle_b.png");
    Texture2D run_b = LoadTexture("sprites/characters/player_run_b.png");
    Vector2 screenPos;
    Vector2 worldPos;
    // 1 : personagem olhando para a direita/ -1 : personagem olhando para a esquerda
    float rightLeft{1.f};

    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};
    const float speed{4.f};

};

void Character::setScreenPos(int winWidth, int winHeight){
    screenPos = {(float)winWidth/2.0f - 4.0f * (0.5f * (float)texture.width/6.0f),
                 (float)winHeight/2.0f - 4.0f * (0.5f * (float)texture.height)};
    }


void Character::tick(float deltaTime){
        Vector2 direction{};

        if(IsKeyDown(KEY_A)){
            direction.x -= 1.0;
            texture = run_s;
        }
        if(IsKeyDown(KEY_D)){
            direction.x += 1.0;
            texture = run_s;
        }
        if(IsKeyDown(KEY_W)){
            direction.y -= 1.0;
            texture = run_b;
        }
        if(IsKeyDown(KEY_S)){
            direction.y += 1.0;
            texture = run_f;
        }

        if(IsKeyReleased(KEY_A))
            texture = idle_s;
        if(IsKeyReleased(KEY_D))
            texture = idle_s;
        if(IsKeyReleased(KEY_W))
            texture = idle_b;
        if(IsKeyReleased(KEY_S))
            texture = idle_f;

        if(Vector2Length(direction) != 0.0){

            //set worldPos = worldPos + direction
            worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
            if (direction.x < 0.f) {
                rightLeft = -1.f;
            }
            else {
                rightLeft = 1.f;
            }
        }
            runningTime += deltaTime;
        if (runningTime >= updateTime){

            frame++;
            runningTime = 0.f;
            if (frame > maxFrames)
                frame = 0;
        }
        //Desenha o personagem
        Rectangle source{frame * (float)texture.width/6.f, 0.f, rightLeft * (float)texture.width/6.f, (float)texture.height};
        Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width/6.0f, 4.0f * (float)texture.height};
        DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);

}
int main(){

    const int windowWidth{1024};
    const int windowHeight{460};

    InitWindow(windowWidth, windowHeight, "Top Down");

    Texture2D map = LoadTexture("sprites/cronge.png"); //Input de backgroud do jogo
    Vector2 mapPos{0.0, 0.0};

    Character hero;
    hero.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);

    while (!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(hero.getWorldPos(), -1.f);

        //Desenha o mapa
        DrawTextureEx(map, mapPos, 4.0, 4.0, WHITE);
        hero.tick(GetFrameTime());

        EndDrawing();

    }
    CloseWindow();


}
