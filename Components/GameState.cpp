#include "GameState.h"
#include "ObjectCollision.h"
#include "stdio.h"


void GameState::play()
{
	if (d = -1)
	{
		d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	}
	arena[0].center = { 0,350 };
	arena[0].size = { 10, 350 };
	arena[0].arenaTransform.m_facing = 0;

	arena[1].center = { 700,350 };
	arena[1].size = { 10, 350 };
	arena[1].arenaTransform.m_facing = 0;

	arena[2].center = { 350,700 };
	arena[2].size = { 350, 10 };
	arena[2].arenaTransform.m_facing = 0;

	arena[3].center = { 350,0 };
	arena[3].size = { 350, 10 };
	arena[3].arenaTransform.m_facing = 0;

	for (int i = 0; i < MAX_ARENA; ++i)
	{
		arena[i].build();
	}

	player.healthP1 = 100;
	player2.healthP2 = 100;
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	player2.transform.m_position = vec2{ 300,300 };
	player2.transform.m_facing = 0;


	bullet.timer = 0;
}
void GameState::update(float deltaTime)
{
	if (player.healthP1 <= 0)
	{
		player2.killsP2 += 1;
		player.healthP1 = 100;
	}
	if (player2.healthP2 <= 0)
	{
		player.killsP1 += 1;
		player2.healthP2 = 100;
	}
	player.update(deltaTime, *this);
	player2.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	bullet.update(deltaTime, *this);
	bullet2.update(deltaTime, *this);

	for (int i = 0; i < MAX_ARENA; ++i)
	{
		arena[i].update(deltaTime, *this);

	
		PlayerArenaCollision(player, arena[i]);
		Player2ArenaCollision(player2, arena[i]);
		BulletArenaCollision(bullet, arena[i]);
		Bullet2ArenaCollision(bullet2, arena[i]);
	}
	for (int i = 0; i < 2; ++i)
		PlayerPlayer2Collision(player, player2);

	for (int i = 0; i < 2; ++i)
		Player2PlayerCollision(player2, player);

	for (int i = 0; i < 2; ++i)
		BulletPlayerCollision(bullet2, player);

	for (int i = 0; i < 2; ++i)
		BulletPlayer2Collision(bullet, player2);




}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
	player2.draw(cam);
	bullet.draw(cam);
	bullet2.draw(cam);

	for (int i = 0; i < MAX_ARENA; ++i)
	{
		arena[i].draw(cam);
	}
	drawOverlay(d, player.healthP1, player2.healthP2, player.killsP1, player2.killsP2);
}
