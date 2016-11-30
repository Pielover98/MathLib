#pragma once

#include "Asteroid.h"
#include "PlayerSpaceShip.h"
#include "Player2SpaceShip.h"
#include "Bullet.h"
#include "Bullet2.h"


void PlayerAsteroidCollision(PlayerSpaceShip &player, Asteroid &as);
void Player2AsteroidCollision(Player2SpaceShip &player2, Asteroid &as);
void PlayerPlayer2Collision( PlayerSpaceShip &player, Player2SpaceShip &player2);
void Player2PlayerCollision(Player2SpaceShip &player2, PlayerSpaceShip &player);
void AsteroidCollision(Asteroid &as1, Asteroid &as2);
void BulletAsteroidP1Collision(Bullet &b, Asteroid &a);
void BulletAsteroidP2Collision(Bullet2 &b, Asteroid &a);
void BulletPlayerCollision(Bullet2 &b, PlayerSpaceShip &player);
void BulletPlayer2Collision(Bullet &b, Player2SpaceShip &player2);





