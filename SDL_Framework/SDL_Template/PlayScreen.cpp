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

	mObstacle = new Obstacle();
	mObstacle->Parent(this);
	mObstacle->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);


	
 
	//game audio
	mAudio->PlaySFX("SFX/8-BitMoonlightSonata.mp3", -1);

}

 
PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;
	mInput = nullptr;
	
	

	delete mPlayer;
	mPlayer = nullptr;

	delete mBackground;
	mBackground = nullptr;

	delete mObstacle;
	mObstacle = nullptr;

	

	
}

void PlayScreen::Update() {
	mPlayer->Update();
	mObstacle->Update();
	mBackground->Update();
	
}

void PlayScreen::Render() {
	mBackground->Render();
	mObstacle->Render();
	mPlayer->Render();

	
	
	
}
