#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceShipLocoMotion.h"
#include "SpaceShipController.h"

void main()
{
	float SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;


	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100}; 

	Transform playerTransform(200,200);
	playerTransform.scale = { 10,10 };

	Rigidbody playerRigidbody;

	SpaceShipLocoMotion playerLoco;
	SpaceShipController playerCtrl;
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		/*
		if (sfw::getKey('W')) playerRigidbody.acceleration.y += 10.0f;
		if (sfw::getKey('S')) playerRigidbody.acceleration.y -= 10.0f;
		if (sfw::getKey('A')) playerRigidbody.acceleration.x -= 10.0f;
		if (sfw::getKey('D')) playerRigidbody.acceleration.x += 10.0f;


		if (sfw::getKey('Q')) playerRigidbody.angularAcceleration += 1.0f;
		if (sfw::getKey('E')) playerRigidbody.angularAcceleration -= 1.0f;
*/
		
		//if (playerTransform.position.x > SCREEN_WIDTH) playerTransform.position.x = 0.0f;
		//else if (playerTransform.position.x < 0.0f) playerTransform = SCREEN_WIDTH;


		//if (playerTransform.position.y > SCREEN_HEIGHT) playerTransform.position.y = 0.0f;
		//else if (playerTransform.position.y < 0.0f)	playerTransform.position.y = SCREEN_HEIGHT;

		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform , playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);
		
		
		playerTransform.debugDraw();
	}
	sfw::termContext();
}