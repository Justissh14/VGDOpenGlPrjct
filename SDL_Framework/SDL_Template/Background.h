#pragma once
#include "AnimatedGLTexture.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "Player.h"


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

	int mScore;

	GameEntity* mGroundBar;

	Player* mPlayer;

	Scoreboard* mTopScore;
	Scoreboard* mPlayerOneScore;

	

public:
	int Score();

	Background();
	~Background();

	void Update() override;
	void Render() override;
};
