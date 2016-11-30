#include "ObjectCollision.h"


void PlayerAsteroidCollision(PlayerSpaceShip & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		
		player.transform.m_scale *= .9f;
	}
}

void Player2AsteroidCollision(Player2SpaceShip & player2, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player2.transform, player2.rigidbody, player2.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{

		player2.transform.m_scale *= .9f;
	}
}
void PlayerPlayer2Collision(PlayerSpaceShip & player, Player2SpaceShip & player2)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
			player2.transform, player2.rigidbody, player2.collider);

	if (result.penetrationDepth >= 0)
	{

		player.transform.m_scale *= .9f;
	}
}
void Player2PlayerCollision(Player2SpaceShip & player2, PlayerSpaceShip & player)
{
	CollisionData result =
		DynamicResolution(player2.transform, player2.rigidbody, player2.collider,
			player.transform, player.rigidbody, player.collider);

	if (result.penetrationDepth >= 0)
	{

		player2.transform.m_scale *= .9f;
	}
}


void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void BulletAsteroidP1Collision(Bullet &b, Asteroid &a)
{
	
	if (!b.isAlive) return;

	
	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			a.transform, a.rigidbody, a.collider);


	if (result.penetrationDepth >= 0)
	{
		b.timer = 0;
	}

}
void BulletAsteroidP2Collision(Bullet2 &b, Asteroid &a)
{

	if (!b.isAlive) return;


	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			a.transform, a.rigidbody, a.collider);


	if (result.penetrationDepth >= 0)
	{
		b.timer = 0;
	}

}
void BulletPlayerCollision(Bullet2 &b, PlayerSpaceShip &player)
{

	if (!b.isAlive) return;


	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			player.transform, player.rigidbody, player.collider);


	if (result.penetrationDepth >= 0)
	{
		b.timer = 0;
	}

}
void BulletPlayer2Collision(Bullet &b, Player2SpaceShip &player2)
{

	if (!b.isAlive) return;


	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			player2.transform, player2.rigidbody, player2.collider);


	if (result.penetrationDepth >= 0)
	{
		b.timer = 0;
	}

}