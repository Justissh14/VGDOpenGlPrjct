#include "Background.h"
#include "Player.h"
#include "AnimatedGLTexture.h"


Background::Background() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mScore = 0;

	

	//Ground (Main)
	mTexture = new GLTexture("SilverSteel.jpg", 7, 15, 1500, -400);
	mTexture->Parent(mGroundBar);
	mTexture->Position(200.0f, 924.5f);

	//Ground (Platform)
	mTexture2 = new GLTexture("RustedSilverSteel.jpg", 7, 15, 1500, -50);
	mTexture2->Parent(mGroundBar);
	mTexture2->Position(200.0f, 745.0f);

	//Hi Score
	mHiScore = new GLTexture("HI SCORE", "emulogic.ttf", 30, { 100, 100, 100 });
	mHiScore->Parent(this);
	mHiScore->Position(-250.0f, -690.0f);

	// High Score Number - (99,999)
	mTopScore = new Scoreboard();
	mTopScore->Parent(this);
	mTopScore->Position(Graphics::SCREEN_WIDTH * 0.03f, -690.0f);
	mTopScore->Score(99999);

	//Player (One)
	mPlayerOne = new GLTexture("Current", "emulogic.ttf", 28, { 100, 100, 100 });
	mPlayerOne->Parent(this);
	mPlayerOne->Position(-Graphics::SCREEN_WIDTH * -0.19f, -690.0f);

	//Player (One Score)
	mPlayerOneScore = new Scoreboard();
	mPlayerOneScore->Parent(this);
	mPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * -0.37f, -690.0f);
	

	mGroundBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	mGroundBar->Parent(this);


	
}

Background::~Background() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;
	delete mTexture;
	mTexture = nullptr;
	delete mTexture2;
	mTexture2 = nullptr;
	delete mHiScore;
	mHiScore = nullptr;
	delete mTopScore;
	mTopScore = nullptr;
	delete mPlayerOneScore;
	mPlayerOneScore = nullptr;
	delete mPlayerOne;
	mPlayerOne = nullptr;
	
	

	delete mGroundBar;
	mGroundBar = nullptr;
	
	

}

//int Player::Score() {
//	return mScore;
//}
//
//void Player::AddScore(int change) {
//	mScore += change;
//}

void Background::Update() {
	mTexture->Update();
	mTexture2->Update();
	mHiScore->Update();
	mTopScore->Update();
	mPlayerOneScore->Update();
	mPlayerOne->Update();
}

void Background::Render() {
	mTexture->Render();
	mTexture2->Render();
	mHiScore->Render();
	mTopScore->Render();
	mPlayerOneScore->Render();
	mPlayerOne->Render();


}