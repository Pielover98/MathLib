 #pragma once

#include "PlayerSpaceShip.h"
#include "Player2SpaceShip.h"
#include "arena.h"
#include "Camera.h"
#include "Bullet.h"
#include "Bullet2.h"
#include "Overlay.h"

const int MAX_ARENA = 16;
class GameState
{
public:

	int d = -1;

	Arena arena[MAX_ARENA];
	PlayerSpaceShip player;
	Player2SpaceShip player2;
	Camera camera;
	Bullet bullet;
	Bullet2 bullet2;


	bool playerWin = false;
	bool player2Win = false;


	void play();				
	void update(float deltaTime); 
	void draw();


};