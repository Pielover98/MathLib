#include "flops.h"
#include <cmath>
bool fequals(float lhs, float rhs)
{
	if (fabs(lhs - rhs) <= 0.00000001f)
	{
		return true;
	}
}
