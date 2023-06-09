#include "Enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D walk_texture):
    worldPos(pos),
    texture(idle_texture),
    idle(idle_texture),
    walk(walk_texture)
{

    width = texture.width/maxFrames;
    height = texture.height;

}

void Enemy::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

            runningTime += deltaTime;
        if (runningTime >= updateTime){

            frame++;
            runningTime = 0.f;
            if (frame > maxFrames)
                frame = 0;
        }
        //Desenha o personagem
        Rectangle source{frame * width, 0.f, rightLeft * width, height};
        Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
        DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void Enemy::undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle Enemy::GetCollisionRec(){
    return Rectangle{
        screenPos.x,
        screenPos.y,
        texture.width * scale,
        texture.height * scale
    };
}
