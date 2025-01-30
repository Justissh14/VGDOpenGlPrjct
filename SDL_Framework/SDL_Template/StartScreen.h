#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "AnimatedGLTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "AudioManager.h"
#include "Player.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {

private:
	Timer * mTimer;
	InputManager * mInput;
	AudioManager* mAudio;

	// Top Bar Entities
	GameEntity * mTopBar;
	Texture * mPlayerOne;
	Texture* mGameTitle;
	Texture* mGameTitle2;
	/*Texture * mPlayerTwo;*/
	Texture * mHiScore;
	Scoreboard * mPlayerOneScore;
	Scoreboard * mPlayerTwoScore;
	Scoreboard * mTopScore;

	// Logo Entities
	/*Texture * mLogo;*/
	Texture* mLogo2;
	/*AnimatedGLTexture * mAnimatedLogo;*/

	// Play Mode Entities
	GameEntity * mPlayModes;
	Texture * mStartGameMode;
	Texture * mCreditMode;
	Texture * mCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	// Bottom Bar Entities
	GameEntity * mBottomBar;
	Texture * mVersion;
	Texture * mInfo;
	Texture * mRights;

	// Screen Animation Variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

public:
	StartScreen();
	~StartScreen();

	void ResetAnimation();

	int SelectedMode();

	void ChangeSelectedMode(int change);

	void Update() override;
	void Render() override;
};
#endif