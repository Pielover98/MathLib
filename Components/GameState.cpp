#include "GameState.h"
#include "ObjectCollision.h"


void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	player2.transform.m_position = vec2{ 300,300 };
	player2.transform.m_facing = 0;


	asteroid[0].transform.m_position = vec2{ 0,0 };
	asteroid[0].rigidbody.addImpulse(vec2{ 100,100 });
	asteroid[0].rigidbody.addTorque(24);

	asteroid[1].transform.m_position = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -100,-100 });
	asteroid[1].rigidbody.addTorque(-24);

	asteroid[2].transform.m_position = vec2{ 500,500 };
	asteroid[2].rigidbody.addImpulse(vec2{ -100,-100 });
	asteroid[2].rigidbody.addTorque(-24);

	bullet.timer = 0;
}
void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	player2.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	bullet.update(deltaTime, *this);
	bullet2.update(deltaTime, *this);

	for (int i = 0; i < 2; ++i)
		asteroid[i].update(deltaTime, *this);

	for (int i = 0; i < 2; ++i)
		PlayerAsteroidCollision(player, asteroid[i]);

	for (int i = 0; i < 2; ++i)
		Player2AsteroidCollision(player2, asteroid[i]);

	for (int i = 0; i < 2; ++i)
		PlayerPlayer2Collision(player, player2);

	for (int i = 0; i < 2; ++i)
		Player2PlayerCollision(player2, player);

	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(asteroid[i], asteroid[j]);

	for (int i = 0; i < 2; ++i)
		BulletAsteroidP1Collision(bullet, asteroid[i]);

	for (int i = 0; i < 2; ++i)
		BulletAsteroidP2Collision(bullet2, asteroid[i]);

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

	for (int i = 0; i < 2; ++i)
		asteroid[i].draw(cam);
}