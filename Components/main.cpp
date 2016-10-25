#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "SpaceshipRenderer.h"

#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"

void main()
{
	float SCREEN_WIDTH = 2160, SCREEN_HEIGHT = 1440;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	float steps = 100;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100 };

	Transform playerTransform(200, 200);

	playerTransform.m_scale = vec2{ 10,20 };
	Rigidbody playerRigidbody;
	SpaceShipController playerCtrl;
	SpaceShipLocoMotion playerLoco;
	SpaceShipRenderer playerRender;
	Transform sunTransform;
	sunTransform.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = 5;
	PlanetaryRenderer sunRenderer(YELLOW, 100);
	Transform plan1;
	plan1.m_position = vec2{ 150, 0 };
	plan1.m_parent = &sunTransform;
	Rigidbody plan1RB;
	PlanetaryMotor plan1motor;
	plan1motor.m_rotationSpeed = 7;
	PlanetaryRenderer plan1renderer(GREEN, 20);
	Transform moon1;
	moon1.m_position = vec2{ 50, 0 };
	moon1.m_parent = &plan1;
	Rigidbody moon1RB;
	PlanetaryMotor moon1motor;
	moon1motor.m_rotationSpeed = 12;
	PlanetaryRenderer moon1renderer(WHITE, 7);


	Transform cameraTransform;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

	
		sunMotor.update(sunRbody);
		plan1motor.update(plan1RB);
		moon1motor.update(moon1RB);

		playerRigidbody.integrate(playerTransform, deltaTime);
		moon1RB.integrate(moon1, deltaTime);
		plan1RB.integrate(plan1, deltaTime);
		sunRbody.integrate(sunTransform, deltaTime);
		cameraTransform.m_position
			= lerp(cameraTransform.m_position,
			(playerTransform.getGlobalPosition()
				+ sunTransform.getGlobalPosition()) / 2,
				sfw::getDeltaTime() * 10);

		mat3 proj = translate(600, 600) * scale(2, 2);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view;

		playerTransform.debugDraw(camera);
		sunTransform.debugDraw(camera);
		plan1.debugDraw(camera);
		moon1.debugDraw(camera);
		cameraTransform.debugDraw(camera);

		playerRigidbody.debugDraw(camera, playerTransform);

		sunRenderer.draw(camera, sunTransform);
		plan1renderer.draw(camera, plan1);
		moon1renderer.draw(camera, moon1);

		playerRender.draw(camera, playerTransform);
	}
	sfw::termContext();
}