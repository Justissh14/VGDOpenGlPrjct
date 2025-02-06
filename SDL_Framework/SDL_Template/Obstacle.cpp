#include "Obstacle.h"
#include "BoxCollider.h"
#include "GameManager.h"
#include "Background.h"
#include <iostream> 


Obstacle::Obstacle() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mMissile = new GLTexture("Missile.png", 0, 10, 135, 250);
	mMissile->Rotate(-90.0f);
	mMissile->Scale(Vector2(0.25f, 0.5f));

	mCrate = new GLTexture("Crate.png", 0, 0, 500, 500);
	mCrate->Position(1000.0f, 670.0f);
	mCrate->Scale(Vector2(0.20f, 0.20f));

	//TODO: need to fix colliders amd possibly move Missile to its own class as an entity


	/*AddCollider(new BoxCollider(Vector2(16.0f, 67.0f)));
	AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(18.0f, 10.0f));
	AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(-18.0f, 10.0f));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::HostileProjectiles);*/


}

Obstacle::~Obstacle() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mMissile;
	mMissile = nullptr;


}

void Obstacle::Update() {

	float missileSpeed = 20.0f; // Speed of missiles 
	float crateSpeed = 15.0f; // Speed of crate

	switch (mInput->KeyPressed(SDL_SCANCODE_R) ? 'R' :
		mInput->KeyPressed(SDL_SCANCODE_E) ? 'E' : 'N') {
	case 'R':
		if (!mMissileActive) {
			if (!mMissile) { // Create only if it doesn't exist
				mMissile = new GLTexture("Missile.png", 0, 10, 135, 250);
				mMissile->Rotate(-90.0f);
				mMissile->Scale(Vector2(0.25f, 0.5f));
			}
			mMissile->Position(1000.0f, 670.0f);
			mMissileActive = true;
		}
		break;

	case 'E':
		if (!mMissileActive) {
			if (!mMissile) { // Create only if it doesn't exist
				mMissile = new GLTexture("Missile.png", 0, 10, 135, 250);
				mMissile->Rotate(-90.0f);
				mMissile->Scale(Vector2(0.25f, 0.5f));
			}
			mMissile->Position(1000.0f, 500.0f);
			mMissileActive = true;
		}
		break;

	default:
		//do nthing
		break;
	}




	if (mMissileActive) {
		mMissile->Position(mMissile->Position().x - missileSpeed, mMissile->Position().y);


		if (mMissile->Position().x < -200) {
			delete mMissile;
			mMissile = nullptr;
			mMissileActive = false;
		}
	}

	// press T to create crates
	if (mInput->KeyPressed(SDL_SCANCODE_T) && !mCratesActive) {
		mCrate = new GLTexture("Crate.png", 0, 0, 500, 500);
		mCrate->Position(1000.0f, 670.0f);
		mCrate->Scale(Vector2(0.20f, 0.20f));
		mCratesActive = true;
	}


	if (mCratesActive) {
		mCrate->Position(mCrate->Position().x - crateSpeed, mCrate->Position().y);

		// If missile is out of screen deactivate it
		if (mCrate->Position().x < -200) {
			delete mCrate;
			mCrate = nullptr;
			mCratesActive = false;
		}
	}

	if (mMissileActive) {
		mMissile->Update();
	}
	if (mCratesActive) {
		mCrate->Update();
	}



}

void Obstacle::Render() {
	if (mMissileActive) {
		mMissile->Render();
	}
	if (mCratesActive) {
		mCrate->Render();
	}
}