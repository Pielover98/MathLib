#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceshipLocomotion.h"


class PlayerSpaceShip
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	SpaceShipController controller;
	SpaceShipLocomotion locomotion;

	int healthP1 = 100;
	int killsP1 = 0;


	PlayerSpaceShip();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};