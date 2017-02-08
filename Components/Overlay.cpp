#include "Overlay.h"

void drawOverlay(unsigned font, int healthP1, int healthP2, int killsP1, int killsP2)
{
	char buffer[64] = { 0 };
	char buffer1[64] = { 0 };
	char buffer2[64] = { 0 };
	char buffer3[64] = { 0 };

	if (healthP1 > 0)
	{
		sprintf_s(buffer, "Player 1 Score: %d", killsP1);
		sfw::drawString(font, buffer, 50, 850, 20, 20);
	}
	if (healthP2 > 0)
	{
		sprintf_s(buffer, "Player 2 Score: %d", killsP2);
		sfw::drawString(font, buffer, 410, 850, 20, 20);
	}
	if (healthP1 > 0)
	{
		sprintf_s(buffer, "Player 1 Health: %d", healthP1);
		sfw::drawString(font, buffer, 780, 850, 20, 20);
	}
	if (healthP2 > 0)
	{
		sprintf_s(buffer, "Player 2 Health: %d", healthP2);
		sfw::drawString(font, buffer, 1200, 850, 20, 20);
	}

	if (healthP1 <= 0)
	{
		sprintf_s(buffer, "Player 1 has died. Player 2 scores a point");
		sfw::drawString(font, buffer, 700, 500, 20, 20);
	}
	if (healthP2 <= 0)
	{
		sprintf_s(buffer, "Player 2 has died. Player 1 scores a point");
		sfw::drawString(font, buffer, 700, 500, 20, 20);
	}
}
