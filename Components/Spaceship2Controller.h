#pragma once
#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
class SpaceShip2Controller
{
public:
	char CTR_LEFT2, CTR_RIGHT2, CTR_UP2, CTR_DOWN2, CTR_BREAK2;
	SpaceShip2Controller(unsigned CTR_LEFT2 = 'J', unsigned CTR_RIGHT2 = 'L', unsigned CTR_UP2 = 'I', unsigned CTR_DOWN2 = 'K', unsigned CTR_BREAK2 = 'M');
	void update(class SpaceShipLocomotion &loco);
};