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

float distance(const Point P1, const Point P2)
{
	return sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y));

}

float inner(const Point3D & P1, const Point3D & P2)
{
	return P1.x*P2.x + P1.y*P2.y + P1.z*P2.z;
}

float point_plane_distance(const Plane & pl, const Point3D & pt)
{
	return (inner(pl.abc, pt) + pl.d) /
		sqrt(pl.abc.x * pl.abc.x
			+ pl.abc.y * pl.abc.y
			+ pl.abc.z * pl.abc.z);
}

Point3D bezier(float t, const Point3D & p1, const Point3D & p2, const Point3D & p3, const Point3D & p4)
{

	float ot = 1 - t;
	Point3D r;
	r.x = ot*ot*ot*p1.x + 3 * ot*ot*t*p2.x + 3 * ot*t*t*p3.x + t*t*t*p4.x;
	r.y = ot*ot*ot*p1.y + 3 * ot*ot*t*p2.y + 3 * ot*t*t*p3.y + t*t*t*p4.y;
	r.z = ot*ot*ot*p1.z + 3 * ot*ot*t*p2.z + 3 * ot*t*t*p3.z + t*t*t*p4.z;
	return r;
}
