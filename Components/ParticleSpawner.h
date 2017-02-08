#pragma once

#include "oobpool.h"
#include "Particle.h"

class ParticleSpawner
{
	// Object pool for the particle storage.
	obpool<Particle> particlePool;

	// Time until next particle spawn.
	float spawnTimer;

public:
	ParticleSpawner();
	ParticleSpawner(float interval, unsigned int particleCount);
	~ParticleSpawner();

	Transform transform;

	// Time between each particle instantiation.
	float spawnInterval;

	// Maximum number of particles.
	unsigned int maxParticles;

	void update(float deltaTime, class GameState &gs);

	void draw(const mat3 &camera);
};