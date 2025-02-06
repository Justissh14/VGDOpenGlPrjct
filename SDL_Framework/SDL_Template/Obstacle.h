#pragma once
#include "AnimatedGLTexture.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "Player.h"
#include "Background.h"
#include "BoxCollider.h"
#include "PhysicsManager.h"
#include "Bullet.h"


using namespace SDLFramework;

class Obstacle : public PhysEntity {
private:
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;



    GLTexture* mMissile;
    GLTexture* mCrate;

    bool mMissileActive = false;
    bool mCratesActive = false;


public:
    Obstacle();
    ~Obstacle();

    /*bool IgnoreCollisions() override;
    void Hit(PhysEntity* other) override;*/

    void Update() override;
    void Render() override;
};

