#pragma once


#include "PlayerSpaceShip.h"
#include "Player2SpaceShip.h"
#include "Arena.h"
#include "Bullet.h"
#include "Bullet2.h"


struct Arena;
void PlayerPlayer2Collision( PlayerSpaceShip &player, Player2SpaceShip &player2);
void Player2PlayerCollision(Player2SpaceShip &player2, PlayerSpaceShip &player);
void BulletPlayerCollision(Bullet2 &b, PlayerSpaceShip &player);
void BulletPlayer2Collision(Bullet &b2, Player2SpaceShip &player2);
void PlayerArenaCollision(PlayerSpaceShip &player, Arena &arena);
void Player2ArenaCollision(Player2SpaceShip &player2, Arena &arena);
void BulletArenaCollision(Bullet &b, Arena &arena);
void Bullet2ArenaCollision(Bullet2 &b2, Arena &arena);





