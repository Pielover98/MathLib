#include "PlayerSpaceShip.h"
#include "GameState.h"


PlayerSpaceShip::PlayerSpaceShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 10,10 };
}

void PlayerSpaceShip::update(float deltaTime, GameState &gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);

	rigidbody.integrate(transform, deltaTime);

	if (sfw::getKey('F') && !gs.bullet.isAlive)
	{
		
		gs.bullet.timer = 2.f;

		
		gs.bullet.transform.m_position = transform.m_position;
		gs.bullet.transform.m_facing = transform.m_facing;

		
		gs.bullet.rigidbody.velocity = vec2{ 0,0 };
		
		gs.bullet.rigidbody.addImpulse(transform.getUp() * 3000.f);
	}
}

void PlayerSpaceShip::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}