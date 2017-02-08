#include "Player2SpaceShip.h"
#include "GameState.h"


Player2SpaceShip::Player2SpaceShip()
{
	vec2 hullVrts[] = { { 0, 3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 10,10 };
}

void Player2SpaceShip::update(float deltaTime, GameState &gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);

	rigidbody.integrate(transform, deltaTime);

	if (sfw::getKey('M') && !gs.bullet2.isAlive)
	{

		gs.bullet2.timer = 2.f;


		gs.bullet2.transform.m_position = transform.m_position;
		gs.bullet2.transform.m_facing = transform.m_facing;
		

		gs.bullet2.rigidbody.velocity = vec2{ 0,0 };

		gs.bullet2.rigidbody.addImpulse(transform.getUp() * 3000.f);
	}
}

void Player2SpaceShip::draw(const mat3 &camera2)
{
	transform.debugDraw(camera2);
	collider.DebugDraw(camera2, transform);
	rigidbody.debugDraw(camera2, transform);
}