#pragma once

class SpaceShipController
{
public:
	char CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;
	SpaceShipController(unsigned CTR_LEFT = 'A', unsigned CTR_RIGHT = 'D', unsigned CTR_UP = 'W', unsigned CTR_DOWN = 'S', unsigned CTR_BREAK = ' ');
	void update(class SpaceShipLocoMotion &loco);
};