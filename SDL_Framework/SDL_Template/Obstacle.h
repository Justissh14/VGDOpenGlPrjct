#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "GameEntity.h"
#include "GLTexture.h"
#include "Timer.h"
#include "Player.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"

class Obstacle : public PhysEntity {
private:
    Timer* mTimer;
    InputManager* mInput;
    AudioManager* mAudio;
    //Background* mBackground;             //NEED TO FINNISH FIXING THE SCORE CHECK

    GLTexture* mMissile;
    GLTexture* mMissile2;
    GLTexture* mCrate;

    bool mMissileActive = false;
    bool mMissile2Active = false;
    bool mCratesActive = false;

public:
    Obstacle();
    ~Obstacle();

    void Update() override;
    void Render() override;
};

#endif
