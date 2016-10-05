#include "SpaceShipController.h"
#include "SpaceShipLocoMotion.h"

#include "sfwdraw.h"

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