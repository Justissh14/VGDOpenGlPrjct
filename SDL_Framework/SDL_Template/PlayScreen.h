#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Player.h"
#include "InputManager.h"
#include "StartScreen.h"
#include "Background.h"
#include "Obstacle.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;
	InputManager* mInput;
	

	Player * mPlayer;
	Background * mBackground;
	Obstacle* mObstacle;
	


	

public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};
#endif