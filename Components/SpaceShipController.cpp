#include "SpaceShipController.h"
#include "SpaceShipLocoMotion.h"

#include "sfwdraw.h"

SpaceShipController::SpaceShipController(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT, unsigned a_CTR_UP, unsigned a_CTR_DOWN, unsigned a_CTR_BREAK)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_UP;
	CTR_DOWN = a_CTR_DOWN;
	CTR_BREAK = a_CTR_BREAK;

}

void SpaceShipController::update(SpaceShipLocoMotion &loco)
{
	float hInput = 0.0f;
	hInput -= sfw::getKey('D');
	hInput += sfw::getKey('A');

	float vInput = 0.0f;
	vInput -= sfw::getKey('S');
	vInput += sfw::getKey('W');

	float bInput = sfw::getKey(' ');

	loco.doStop(bInput);
	loco.doTurn(hInput);
	loco.doThrust(vInput);
}