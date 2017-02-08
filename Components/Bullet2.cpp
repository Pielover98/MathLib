#include "Bullet2.h"

Bullet2::Bullet2()
{
	timer = 0;

	vec2 hullVrts[] = { { -.1f, 0 },{ 0,.2f },{ .1f,0 } };
	collider = Collider(hullVrts, 3);
	transform.m_scale = vec2{ 40,40 };
	rigidbody.mass = 10;
}

void Bullet2::update(float deltaTime, GameState & gs)
{

	timer -= deltaTime;
	isAlive = timer > 0;

	if (!isAlive) return;

	rigidbody.integrate(transform, deltaTime);
}

void Bullet2::draw(const mat3 & camera)
{
	if (!isAlive) return;

	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}