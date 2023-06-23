#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D walk_texture);
    void tick(float deltaTime);
    void SetTarget(Character* character) {target = character;}
    virtual Vector2 getScreenPos() override;
private:
    int maxFrames{4};
    Character* target;
};
