#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D walk_texture)
{

    worldPos = pos;
    texture = idle_texture;
    idle_f = idle_texture;
    run_s = walk_texture;
    width = texture.width/maxFrames;
    height = texture.height;
    speed = 2.5f;

}

void Enemy::tick(float deltaTime)
{
    //pegar toTarget
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), getScreenPos());
    //normalizar toTarget
    toTarget = Vector2Normalize(toTarget);
    //multiplicar toTarget e Speed
    toTarget = Vector2Scale(toTarget, speed);
    //mover o inimigo em direcao ao personagem
    worldPos = Vector2Add(worldPos, toTarget);
    BaseCharacter::tick(deltaTime);
    //set worldPos = worldPos + direction
    if(Vector2Length(velocity) != 0.0){
            worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
            if (velocity.x < 0.f) {
                rightLeft = -1.f;
            }
            else {
                rightLeft = 1.f;
            }
            int maxFrames{7};
            texture = run_s;
        }
        else {
            int maxFrames{4};
            texture = idle_f;
        }
        velocity = {};

}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}

