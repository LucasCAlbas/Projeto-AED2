#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D walk_texture);
    Vector2 getWorldPos(){ return worldPos; }
    void tick(float deltaTime);
    void undoMovement();
    Rectangle GetCollisionRec();
private:
    Texture2D texture = LoadTexture("sprites/characters/slime_idle.png");
    Texture2D idle = LoadTexture("sprites/characters/slime_idle.png");
    Texture2D walk = LoadTexture("sprites/characters/slime_walk.png");
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1 : personagem olhando para a direita/ -1 : personagem olhando para a esquerda
    float rightLeft{1.f};

    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f/12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{3.0f};

};
