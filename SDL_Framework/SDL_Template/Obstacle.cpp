#include "Obstacle.h"
#include "BoxCollider.h"
#include "GameManager.h"
#include "Background.h"
#include <iostream>
#include <cstdlib>
#define DEBUG_COLLIDERS true

//Rand class wasnt working so had to stick with the OG method
#include <ctime>  

Obstacle::Obstacle() {
    mTimer = Timer::Instance();
    mInput = InputManager::Instance();
    mAudio = AudioManager::Instance();
    

    // Initialize textures for missile and crate
    mMissile = new GLTexture("Missile.png", 0, 10, 135, 250);
    mMissile->Rotate(-90.0f);
    mMissile->Scale(Vector2(0.25f, 0.5f));

    mMissile2 = new GLTexture("Missile.png", 0, 10, 135, 250);
    mMissile2->Rotate(-90.0f);
    mMissile2->Scale(Vector2(0.25f, 0.5f));

    mCrate = new GLTexture("Crate.png", 0, 0, 500, 500);
    mCrate->Position(1000.0f, 670.0f); // Crate's starting position
    mCrate->Scale(Vector2(0.20f, 0.20f));

    AddCollider(new BoxCollider(Vector2(16.0f, 67.0f)));
    AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(18.0f, 10.0f));
    AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(-18.0f, 10.0f));


    mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::FriendlyProjectiles);

    mMissileActive = false;  // Initially inactive
    mMissile2Active = false;
    mCratesActive = false;   // Initially inactive

    
    std::srand(std::time(0));  
}

Obstacle::~Obstacle() {
    mTimer = nullptr;
    mInput = nullptr;
    mAudio = nullptr;

    delete mMissile;
    mMissile = nullptr;

    delete mMissile2;
    mMissile2 = nullptr;

    delete mCrate;
    mCrate = nullptr;
}

void Obstacle::Update() {
    float missileSpeed = 25.0f; // Speed of missiles 25 seems balanced to me
    float crateSpeed = 13.0f;   // Speed of crate 13 seems balanced to me

    
        if (!mMissileActive) {
            if (std::rand() % 350 < 1) {  // 1/350 chance to spawn missile
                mMissile->Position(Vector2(1000.0f, 500.0f));  // Random position for missile
                mMissileActive = true;
            }
        }
        if (!mMissile2Active) {
            if (std::rand() % 200 < 1) {  // 1/200 chance to spawn missile
                mMissile2->Position(Vector2(1000.0f, 670.0f));  // Random position for missile
                mMissile2Active = true;
            }
        }

        if (!mCratesActive) {
            if (std::rand() % 100 < 4) {  // 4% chance to spawn crate
                mCrate->Position(Vector2(1000.0f, 670.0f));  // Crate's starting position
                mCratesActive = true;
            }
        }
    
       
            if (mMissileActive) {
                mMissile->Position(mMissile->Position().x - missileSpeed, mMissile->Position().y);

                if (mMissile->Position().x < -200) {
                    mMissileActive = false;
                }
            }
        

    
        if (mMissile2Active) {
            mMissile2->Position(mMissile2->Position().x - missileSpeed, mMissile2->Position().y);

            if (mMissile2->Position().x < -200) {
                mMissile2Active = false;
            }
        }
   

    
        if (mCratesActive) {
            mCrate->Position(mCrate->Position().x - crateSpeed, mCrate->Position().y);

            if (mCrate->Position().x < -200) {
                mCratesActive = false;
            }
        }
    

    if (mMissileActive) {
        mMissile->Update();
    }
    if (mMissile2Active) {
        mMissile2->Update();
    }
    if (mCratesActive) {
        mCrate->Update();
    }
}

void Obstacle::Render() {
    if (mMissileActive) {
        mMissile->Render();
        PhysEntity::Render();
    }

    if (mMissile2Active) {
        mMissile2->Render();
        PhysEntity::Render();
    }

    
    if (mCratesActive) {
        mCrate->Render();
        PhysEntity::Render();
    }
}
