#pragma once
#include "AnimatedGLTexture.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "Player.h"
#include "Obstacle.h"





using namespace SDLFramework;

class Background : public GameEntity{
private:
	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;

	
	Texture* mHiScore;
	Texture* mPlayerOne;
	Texture* mBackDrop;
	Texture* mTexture;
	Texture* mTexture2;
	Texture* mTexture3;

	float mElapsedTime = 0.0f;

	int mScore;

	GameEntity* mGroundBar;
	

	Player* mPlayer;

	Scoreboard* mTopScore;
	Scoreboard* mPlayerOneScore;

	

	
	

public:
	

	Background();
	~Background();

	float mTextureWidth;
    float mTexture2Width;

	void Update() override;
	void Render() override;
};
