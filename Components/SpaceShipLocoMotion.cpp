#include "SpaceShipLocoMotion.h"
#include "sfwdraw.h"

SpaceShipLocoMotion::SpaceShipLocoMotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	breakPower = 10.0f;
	turnSpeed = 10.0f;
	speed = 500.0f;
	maxSpeed = 1000.0f;

}

void SpaceShipLocoMotion::doThrust(float value)
{ vertThrust += value; }

void SpaceShipLocoMotion::doTurn(float value)
{ horzThrust += value; }

void SpaceShipLocoMotion::doStop(float value)
{ stopAction += value; }

void SpaceShipLocoMotion::update(const Transform &trans, Rigidbody & rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);


	//float currentSpeed = magnitude(rigidbody.velocity);


	//-normal(rigidbody.velocity);
	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);
	horzThrust = vertThrust = stopAction = 0;
}


