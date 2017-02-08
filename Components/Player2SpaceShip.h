#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "Spaceship2Controller.h"
#include "SpaceshipLocomotion.h"


class Player2SpaceShip
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	SpaceShip2Controller controller;
	SpaceShipLocomotion locomotion;

	int healthP2 = 100;
	int killsP2 = 0;

	Player2SpaceShip();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera2);
};