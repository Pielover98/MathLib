#include "SpaceshipLocomotion.h"

#include "sfwdraw.h"

SpaceShipLocomotion::SpaceShipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	stopAction = 0.0f;
	breakPower = 4.0f;

	
	turnSpeed = 4.0f;

	
	speed = 900.0f;
	maxSpeed = 1000.0f;
}

void SpaceShipLocomotion::doThrust(float value)
{
	vertThrust += value;
}

void SpaceShipLocomotion::doTurn(float value)
{
	horzThrust += value;
}

void SpaceShipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceShipLocomotion::update(const Transform &trans,
	Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThrust = vertThrust = stopAction = 0;
}