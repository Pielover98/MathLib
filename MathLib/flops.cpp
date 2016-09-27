#include "flops.h"
#include <cmath>
bool fequals(float lhs, float rhs)
{
	if (fabs(lhs - rhs) <= 0.00001f)
	{
		return true;
	}

	return false;
}

float deg2rad(float deg)
{
	return deg * 3.14159265f / 180;
}

float rad2deg(float rad)
{
	return rad * 180 / 3.14159265f;
}
