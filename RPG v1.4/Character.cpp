#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)
{

    width = texture.width/maxFrames;
    height = texture.height;

}

Vector2 Character::getScreenPos()
{
      return Vector2{
        static_cast<float>(windowWidth)/2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight)/2.0f - scale * (0.5f * height)
     };
}

void Character::tick(float deltaTime){

        if(!getAlive()) return;

        BaseCharacter::tick(deltaTime);

        worldPosLastFrame = worldPos;

        Vector2 direction{};

        if(IsKeyDown(KEY_A)){
            direction.x -= 1.0;
            texture = run_s;
            if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_s;
            }
        }
        if(IsKeyDown(KEY_D)){
            direction.x += 1.0;
            texture = run_s;
                if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_s;
            }
        }
        if(IsKeyDown(KEY_W)){
            direction.y -= 1.0;
            texture = run_b;
                if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_b;
            }
        }
        if(IsKeyDown(KEY_S)){
            direction.y += 1.0;
            texture = run_f;
            if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_f;
            }
        }

        if(IsKeyReleased(KEY_A)){
            texture = idle_s;
                if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_s;
            }
        }
        if(IsKeyReleased(KEY_D)){
            texture = idle_s;
                if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_s;
            }
        }
        if(IsKeyReleased(KEY_W)){
            texture = idle_b;
            if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_b;
            }
        }
        if(IsKeyReleased(KEY_S)){
            texture = idle_f;
            if(IsKeyDown(KEY_J)){
                int maxFrames{4};
                texture = attack_f;
            }
        }

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

}


