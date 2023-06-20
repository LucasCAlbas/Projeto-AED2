#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight){
    width = texture.width/maxFrames;
    height = texture.height;

    screenPos = {static_cast<float>(winWidth)/2.0f - scale * (0.5f * width),
                 static_cast<float>(winHeight)/2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime){

        worldPosLastFrame = worldPos;

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
        Rectangle source{frame * width, 0.f, rightLeft * width, height};
        Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
        DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void Character::undoMovement(){
    worldPos = worldPosLastFrame;
}
