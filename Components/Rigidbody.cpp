#include "Rigidbody.h"
#include "sfwdraw.h"

Rigidbody::Rigidbody()
{
	
	force = impulse = vec2{ 0, 0 };
	acceleration = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angularAcceleration = 0.0f;
	torque = 0.0f;
	mass = 1.0f;
	drag = 1.0f;
	angularDrag = 2.0f;
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
	force = -velocity * drag;
	torque = 0;
	torque = -angularVelocity * angularDrag;

	trans.position += velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity * deltaTime;
}

void Rigidbody::debugDraw(const Transform & trans)
{
	vec2 p = trans.position;
	vec2 v = p + velocity;
	vec2 a = acceleration + p;
	sfw::drawLine(p.x, p.y, v.x, v.y, CYAN);
	sfw::drawLine(v.x, v.y, a.x, a.y, MAGENTA);
}
