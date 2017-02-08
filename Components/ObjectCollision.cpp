#include "ObjectCollision.h"


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


void BulletPlayerCollision(Bullet2 &b2, PlayerSpaceShip &player)
{

	if (!b2.isAlive) return;


	CollisionData result =
		DynamicResolution(b2.transform, b2.rigidbody, b2.collider,
			player.transform, player.rigidbody, player.collider);


	if (result.penetrationDepth >= 0)
	{

		player.healthP1 -= 10;
		b2.timer = 0;
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
		player2.healthP2 -= 10;
		b.timer = 0;
	}

}
void PlayerArenaCollision(PlayerSpaceShip & player, Arena & arena)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
			arena.arenaTransform, arena.arenaCollider);

	
}

void Player2ArenaCollision(Player2SpaceShip & player2, Arena & arena)
{
	CollisionData result =
		StaticResolution(player2.transform, player2.rigidbody, player2.collider,
			arena.arenaTransform, arena.arenaCollider);

	
}

void BulletArenaCollision(Bullet & b, Arena & arena)
{
	if (!b.isAlive) return;
	CollisionData result =
		StaticResolution(b.transform, b.rigidbody, b.collider,
			arena.arenaTransform, arena.arenaCollider);

	if (result.penetrationDepth >= 0)
	{
		b.timer = 0;
	}
}
void Bullet2ArenaCollision(Bullet2 & b2, Arena & arena)
{

	if (!b2.isAlive) return;
	CollisionData result =
		StaticResolution(b2.transform, b2.rigidbody, b2.collider,
			arena.arenaTransform, arena.arenaCollider);

	if (result.penetrationDepth >= 0)
	{
		b2.timer = 0;
	}
}
