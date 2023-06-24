#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter(){



}

void BaseCharacter::undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec(){
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        texture.width * scale,
        texture.height * scale
    };
}

void BaseCharacter::tick(float deltaTime){

     //refresca frame da animacao
            runningTime += deltaTime;
        if (runningTime >= updateTime){

            frame++;
            runningTime = 0.f;
            if (frame > maxFrames)
                frame = 0;
        }

        //Desenha o personagem
        Rectangle source{frame * width, 0.f, rightLeft * width, height};
        Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
        DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

