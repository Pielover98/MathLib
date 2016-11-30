#include "Spaceship2Controller.h"

#include "sfwdraw.h"

SpaceShip2Controller::SpaceShip2Controller(unsigned a_CTR_LEFT2, unsigned a_CTR_RIGHT2,
	unsigned a_CTR_UP2, unsigned a_CTR_DOWN2,
	unsigned a_CTR_BREAK2)
{
	CTR_LEFT2 = a_CTR_LEFT2;
	CTR_RIGHT2 = a_CTR_RIGHT2;
	CTR_UP2 = a_CTR_UP2;
	CTR_DOWN2 = a_CTR_DOWN2;
	CTR_BREAK2 = a_CTR_BREAK2;
}

void SpaceShip2Controller::update(SpaceShipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput -= sfw::getKey(CTR_RIGHT2);
	hInput += sfw::getKey(CTR_LEFT2);

	float vInput = 0.0f;
	vInput += sfw::getKey(CTR_UP2);
	vInput -= sfw::getKey(CTR_DOWN2);

	float bInput = sfw::getKey(CTR_BREAK2);

	loco.doStop(bInput);
	loco.doTurn(hInput);
	loco.doThrust(vInput);
}
