#pragma once
#include "RigidBody.h"
class SpaceShipLocoMotion
{
	float vertThrust;
	float horzThrust;
	float stopAction;
	float breakPower;
	float turnSpeed;
	float speed;
	float maxSpeed;

public:
	SpaceShipLocoMotion();
	

	void doThrust(float value);
	void doTurn(float value);
	void doStop(float value);

	void update(const Transform &trans,Rigidbody &rigidbody);
};