#include "test.h"
#include <math.h>

int doNothing(int x)
{
	return x*x + 2 * x + 5;
}

float test_quad(float x)
{
	return x*x + 2 * x - 7;
}

quad_results quad(float a, float b, float c)
{
	float d;
	quad_results q;

	d = b*b - 4 * a*c;

	if (d < 0)
	{
		q.roots = 0;
	}
	else if (d == 0.0f)
	{
		q.roots = 1;
	}
	else
	{
		q.roots = 2;
	}


	d = sqrt(b*b - 4 * a*c);
	q.left_root = (-1*b - d) / (2 * a);
	q.right_root = (-1 * b + d) / (2 * a);

	return q;
}

float lerp(float start, float end, float t)
{
	return start + t * (end - start);
}

float distance(Point P1, Point P2)
{

	return 0.0f;
}

float inner(Point3D P1, Point3D P2)
{
	return 0.0f;
}
