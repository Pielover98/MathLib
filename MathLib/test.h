#pragma once

int doNothing(int x);

float test_quad(float x);

struct quad_results
{
	float left_root, right_root;
	int roots;
};

quad_results quad(float a, float b, float c);



float lerp(float start, float end, float t);


struct Point { float x, y; };
float distance(Point P1, Point P2);

struct Point3D { float x, y, z; };
float inner(Point3D P1, Point3D P2);