#include "Background.h"
#include "Player.h"
#include "AnimatedGLTexture.h"
#include "GameManager.h"
#include "Obstacle.h"
	



Background::Background() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();
	
	mScore = 0;

	//Ground (left)
	mTexture = new GLTexture("RustedSilverSteel.jpg", 7, 15, 5000, -400);
	mTexture->Parent(mGroundBar);
	mTexture->Position(200.0f, 924.5f);
	mTextureWidth = 1000;  // The width of the texture
	
	//Ground (Right)
	mTexture2 = new GLTexture("RustedSilverSteel.jpg", 7, 15, 5000, -400);
	mTexture2->Parent(mGroundBar);
	mTexture2->Position(200.0f, 924.5f);
	mTexture2Width = 1000;  // The width of  second the texture

	//Hi Score
	mHiScore = new GLTexture("HI SCORE", "Wedgie Regular.ttf", 30, { 0, 0, 0 });
	mHiScore->Parent(this);
	mHiScore->Position(-250.0f, -690.0f);

	// High Score Number - (99,999)
	mTopScore = new Scoreboard();
	mTopScore->Parent(this);
	mTopScore->Position(Graphics::SCREEN_WIDTH * 0.03f, -690.0f);
	mTopScore->Score(99999);

	//Player (One)
	mPlayerOne = new GLTexture("Distance", "Wedgie Regular.ttf", 28, { 0, 0, 0 });
	mPlayerOne->Parent(this);
	mPlayerOne->Position(-Graphics::SCREEN_WIDTH * -0.19f, -690.0f);

	//Player (One Score)
	mPlayerOneScore = new Scoreboard();
	mPlayerOneScore->Parent(this);
	mPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * -0.37f, -690.0f);

	mTexture3 = new GLTexture("SpaceIcon.png", 200, 100, 650, 650);
	mTexture3->Parent(this);
	mTexture3->Position(-200.0f, -295.0f);
	mTexture3->Scale(Vector2(2.5f, 3.0f));
	

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

	

	

	delete mTexture3;
	mTexture3 = nullptr;
	
	

	delete mGroundBar;
	mGroundBar = nullptr;

	

}



void Background::Update() {
	
	// If mTexture2 moves completly off screen move it to right of mTexture
	if (mTexture2->Position().x <= -mTexture2Width) {
		mTexture2->Position(mTexture->Position().x + mTextureWidth, mTexture2->Position().y);
	}

	// 1 point per second
	mElapsedTime += mTimer->DeltaTime();
	if (mElapsedTime >= 1.0f) {
		mElapsedTime = 0.0f;  // Reset timer
		mScore++;       // Increase score
		mPlayerOneScore->Score(mScore);  
	}

	if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
		mScore = 0;
	}

	// Speed both textures move to the left
		float speed = 8.0f; // 8 Feels just about right

	// Move both textures to the left
	mTexture->Position(mTexture->Position().x - speed, mTexture->Position().y);
	mTexture2->Position(mTexture2->Position().x - speed, mTexture2->Position().y);
	
	if (mTexture->Position().x <= -mTextureWidth) {
		mTexture->Position(mTexture2->Position().x + mTextureWidth, mTexture->Position().y);
	}

	
	mTexture->Update();
	mTexture2->Update();
	mHiScore->Update();
	mTopScore->Update();
	mPlayerOneScore->Update();
	mPlayerOne->Update();
	mTexture3->Update();

	
}

void Background::Render() {
	mTexture3->Render();  // Background image
	mTopScore->Render();
	mHiScore->Render();
	mTexture->Render();
	mTexture2->Render();
	mPlayerOneScore->Render();
	mPlayerOne->Render();

	
}
