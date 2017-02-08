#pragma once

#include "Transform.h"
#include "Rigidbody.h"

class Particle
{


public:
	Transform transform;
	Rigidbody rigidbody;

	float lifetime; // how much time left to live

					// Returns true if the particle has expended its lifetime.
	bool isExpired() const;

	// Ticks down the lifetime and update the rigidbody.
	void update(float deltaTime, class GameState &gs);

	// Drawing the particle.
	void draw(const mat3 &camera);
};