#include "Particle.h"

#include "GameState.h"

bool Particle::isExpired() const
{
	return lifetime <= 0;
}

void Particle::update(float deltaTime, GameState &gs)
{
	if (isExpired()) { return; } // exit early if expired

	lifetime -= deltaTime;
	rigidbody.integrate(transform, deltaTime);
}

void Particle::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
}