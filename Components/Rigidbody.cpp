#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	force = vec2{ 0, 0 };
	impulse = vec2{ 0, 0 };
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };

	torque = 0.0f;
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;

	mass = 1;
}

void Rigidbody::addForce(const vec2 & a_force)
{
	force += a_force;
}

void Rigidbody::addImpulse(const vec2 & a_impulse)
{
	impulse += a_impulse;
}

void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
}

void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	acceleration = force / mass;
	velocity += acceleration * deltaTime + impulse / mass;




	angularAcceleration = torque / mass;
	angularVelocity = angularVelocity + angularAcceleration * deltaTime;


	force = impulse = { 0, 0 };
	torque = 0;

	trans.position += velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}