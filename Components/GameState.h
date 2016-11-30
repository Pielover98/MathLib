#pragma once

#include "PlayerSpaceShip.h"
#include "Player2SpaceShip.h"
#include "Camera.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Bullet2.h"

class GameState
{

public:
	PlayerSpaceShip player;
	Player2SpaceShip player2;
	Camera camera;
	Asteroid asteroid[2];
	Bullet bullet;
	Bullet2 bullet2;

	void play();				
	void update(float deltaTime); 
	void draw();


};