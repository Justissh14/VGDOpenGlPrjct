#include "PlayScreen.h"
#include "ScreenManager.h"
#include "InputManager.h"




PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();
	

	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.9f);
	
	mBackground = new Background();
	mBackground->Parent(this);
	mBackground->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);

	
 
	//game audio
	mAudio->PlaySFX("Music/level2.mp3", -1);

}

 
PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;
	mInput = nullptr;
	
	/*delete mHiScore;
	mHiScore = nullptr;*/
	/*delete mTopBar;
	mTopBar = nullptr;*/

	delete mPlayer;
	mPlayer = nullptr;

	delete mBackground;
	mBackground = nullptr;

	
}

void PlayScreen::Update() {
	mPlayer->Update();
	mBackground->Update();
}

void PlayScreen::Render() {
	mPlayer->Render();
	/*mHiScore->Render();*/
	mBackground->Render();
}
