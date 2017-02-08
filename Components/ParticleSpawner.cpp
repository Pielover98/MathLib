#include "ParticleSpawner.h"

#include "GameState.h"
#include "Factory.h"

ParticleSpawner::ParticleSpawner()
{
	spawnTimer = 0;
}

ParticleSpawner::ParticleSpawner(float interval, unsigned int particleCount) : ParticleSpawner()
{
	spawnInterval = interval;
	maxParticles = particleCount;

	spawnTimer = spawnInterval;
}

ParticleSpawner::~ParticleSpawner()
{

}

void ParticleSpawner::update(float deltaTime, GameState &gs)
{
	// tick the spawn timer
	spawnTimer -= deltaTime;

	// check to see if a new particle should be spawned
	if (spawnTimer <= 0 && particlePool.count() < maxParticles)
	{
		// spawn a new particle
		Particle temp = Factory::makeSimpleParticle(2.5f, { 0,0 }, { 50,50 });

		// parent it to the spawner
		temp.transform.m_parent = &transform;

		// give it a force
		temp.rigidbody.addForce({ 0, 500 });

		particlePool.push(temp);

		spawnTimer = spawnInterval;
	}

	// update all applicable particles
	for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter)
	{
		(*iter).update(deltaTime, gs);

		// free any expired particles
		if ((*iter).isExpired())
		{
			iter.free();
		}
	}
}

void ParticleSpawner::draw(const mat3 &camera)
{
	for (auto iter = particlePool.begin(); iter != particlePool.end(); ++iter)
	{
		(*iter).draw(camera);
	}
}