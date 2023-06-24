#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"
//como o inimigo e o personagem usam muitas das mesmas variaveis e funcoes, podemos declara-los aqui.
class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos(){ return worldPos; }
    void undoMovement();
    Rectangle GetCollisionRec();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0;
    bool getAlive(){ return alive; }
    void setAlive(bool isAlive){ alive = isAlive; }
protected:
    Texture2D texture = LoadTexture("sprites/characters/player_idle_f.png");
    Texture2D idle_f = LoadTexture("sprites/characters/player_idle_f.png");
    Texture2D run_f = LoadTexture("sprites/characters/player_run_f.png");
    Texture2D idle_s = LoadTexture("sprites/characters/player_idle_s.png");
    Texture2D run_s = LoadTexture("sprites/characters/player_run_s.png");
    Texture2D idle_b = LoadTexture("sprites/characters/player_idle_b.png");
    Texture2D run_b = LoadTexture("sprites/characters/player_run_b.png");
    Texture2D attack_f = LoadTexture("sprites/characters/player_attack_f.png");
    Texture2D attack_b = LoadTexture("sprites/characters/player_attack_b.png");
    Texture2D attack_s = LoadTexture("sprites/characters/player_attack_s.png");
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1 : personagem olhando para a direita/ -1 : personagem olhando para a esquerda
    float rightLeft{1.f};
    //variaveis para a animacao
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f/12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{3.0f};
    Vector2 velocity{};

private:
    bool alive{true};
};

#endif
