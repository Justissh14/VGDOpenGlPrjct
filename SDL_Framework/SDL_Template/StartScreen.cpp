#include "StartScreen.h"
#include "Player.h"





StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	// top bar entities
	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	
	mGameTitle = new GLTexture("Jet-Pack Runner", "Wedgie Regular.ttf", 58, { 0, 0, 0 });
	mGameTitle2 = new GLTexture("SPACE", "Wedgie Regular.ttf", 80, { 0, 0, 0 });
	mPlayerOne = new GLTexture("Current:", "Wedgie Regular.ttf", 28, { 0, 0, 0 });
	/*mPlayerTwo = new GLTexture("2UP", "emulogic.ttf", 32, { 200, 0, 0 });*/
	mHiScore = new GLTexture("HI SCORE:", "Wedgie Regular.ttf", 30, { 0, 0, 0 });
	mPlayerOneScore = new Scoreboard();
	/*mPlayerTwoScore = new Scoreboard();*/
	mTopScore = new Scoreboard();

	mTopBar->Parent(this);
	mGameTitle->Parent(mTopBar);
	mGameTitle2->Parent(mTopBar);
	mPlayerOne->Parent(mTopBar);
	/*mPlayerTwo->Parent(mTopBar);*/
	mHiScore->Parent(mTopBar);
	mPlayerOneScore->Parent(mTopBar);
	//mPlayerTwoScore->Parent(mTopBar);
	mTopScore->Parent(mTopBar);
	mGameTitle->Position(-10.0f, 100.0f);
	mGameTitle2->Position(0.0f, 250.0f);
	mPlayerOne->Position(-Graphics::SCREEN_WIDTH * -0.19f, -55.0f);
	/*mPlayerTwo->Position(Graphics::SCREEN_WIDTH * 0.2f, 0.0f);*/
	mHiScore->Position(-250.0f, -55.0f); // Width / Height

	mPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * -0.37f, -55.0f);
	//mPlayerTwoScore->Position(Graphics::SCREEN_WIDTH * 0.32f, 40.0f);
	mTopScore->Position(Graphics::SCREEN_WIDTH * 0.03f, -55.0f);

	mTopScore->Score(99999);

	// logo entities
	/*mLogo = new GLTexture("GalagaLogo.png", 0, 0, 360, 180);*/
	//mAnimatedLogo = new AnimatedGLTexture("GalagaLogo.png", 0, 0, 360, 180, 3, 0.2f, Animation::Layouts::Vertical);

	//This image is purposley distorted and colored blck and whte it is not an accident
	mLogo2 = new GLTexture("SpaceIcon.png", 200, 100, 650, 650);
	mLogo2->Scale(Vector2(2.5f, 3.5f));
	/*mLogo->Parent(this);*/
	mLogo2->Parent(this);
	//mAnimatedLogo->Parent(this);

	/*mLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);*/
	mLogo2->Position(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.55f);
	//mAnimatedLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);

	// play mode entities
	mPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mStartGameMode = new GLTexture("Start ", "Wedgie Regular.ttf", 35, { 0, 0, 0 });
	mCreditMode = new GLTexture("Credits", "Wedgie Regular.ttf", 32, { 0, 0, 0 });
	mCursor = new GLTexture("Cursor.png");

	mPlayModes->Parent(this);
	mStartGameMode->Parent(mPlayModes);
	mCreditMode->Parent(mPlayModes);
	mCursor->Parent(mPlayModes);

	mStartGameMode->Position(0.0f, -35.0f);
	mCreditMode->Position(0.0f, 35.0f);
	mCursor->Position(-175.0f, -35.0f);

	mCursorStartPos = mCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0;

	//TODONEW

	// bottom bar entities
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	mVersion = new GLTexture(" v1.0 ", "Wedgie Regular.ttf", 40, { 0, 0, 0 });
	mInfo = new GLTexture("Early Demo.", "Wedgie Regular.ttf", 32, { 0, 0, 0 });
	mRights = new GLTexture("ALL RIGHTS RESERVED", "Wedgie Regular.ttf", 32, { 0, 0, 0 });

	mBottomBar->Parent(this);
	mVersion->Parent(mBottomBar);
	mInfo->Parent(mBottomBar);
	mRights->Parent(mBottomBar);

	mVersion->Position(Vec2_Zero);
	mInfo->Position(0.0f, 90.0f);
	mRights->Position(0.0f, 170.0f);

	// screen animation variables
	ResetAnimation();
}


StartScreen::~StartScreen() {
	// top bar entities
	
	delete mTopBar;
	mTopBar = nullptr;
	delete mPlayerOne;
	mPlayerOne = nullptr;
	delete mGameTitle;
	mGameTitle = nullptr;
	delete mGameTitle2;
	mGameTitle2 = nullptr;

	/*delete mPlayerTwo;
	mPlayerTwo = nullptr;*/

	delete mHiScore;
	mHiScore = nullptr;
	delete mPlayerOneScore;
	mPlayerOneScore = nullptr;
	delete mPlayerTwoScore;
	mPlayerTwoScore = nullptr;
	delete mTopScore;
	mTopScore = nullptr;

	// logo entities
	/*delete mLogo;
	mLogo = nullptr;*/

	delete mLogo2;
	mLogo2 = nullptr;

	/*delete mAnimatedLogo;
	mAnimatedLogo = nullptr;*/

	// play mode entities
	delete mPlayModes;
	mPlayModes = nullptr;
	delete mStartGameMode;
	mStartGameMode = nullptr;
	delete mCreditMode;
	mCreditMode = nullptr;
	delete mCursor;
	mCursor = nullptr;

	// bottom bar entities
	delete mBottomBar;
	mBottomBar = nullptr;
	delete mVersion;
	mVersion = nullptr;
	delete mInfo;
	mInfo = nullptr;
	delete mRights;
	mRights = nullptr;

	mTimer = nullptr;
	mInput = nullptr;
	
}

void StartScreen::ResetAnimation() {
	mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Position(mAnimationStartPos);
}

int StartScreen::SelectedMode() {
	return mSelectedMode;
}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	mCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

void StartScreen::Update() {
	if (!mAnimationDone) {
		mAnimationTimer += mTimer->DeltaTime();
		Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));

		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
		}

		if (mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_UP)) {
			mAnimationTimer = mAnimationTotalTime;
		}
	}
	else {
		/*mAnimatedLogo->Update();*/

		if (mInput->KeyPressed(SDL_SCANCODE_DOWN)) {
			ChangeSelectedMode(1);
			mAudio->PlaySFX("SFX/BlipCoin.mp3", 0, 1);
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_UP)) {
			ChangeSelectedMode(-1);
			mAudio->PlaySFX("SFX/BlipCoin.mp3", 0, 1);
		}
	}
}

void StartScreen::Render() {
	mLogo2->Render();
	mPlayerOne->Render();
	/*mPlayerTwo->Render();*/
	mHiScore->Render();
	mPlayerOneScore->Render();
	/*mPlayerTwoScore->Render();*/
	mTopScore->Render();
	mGameTitle->Render();
	mGameTitle2->Render();

	if (!mAnimationDone) {
		/*mLogo->Render();*/
		
	}
	else {
		/*mAnimatedLogo->Render();*/
	}
	//if i want mLogo2 to disapear after load in is done than put tmLogo2->Render() inside of the if statement
	
	mStartGameMode->Render();
	mCreditMode->Render();
	mCursor->Render();
	

	mVersion->Render();
	mInfo->Render();
	mRights->Render();
	
	
}