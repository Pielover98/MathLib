#pragma once


int doNothing(int x);
float test_quad(float x);


struct quad_results
{
	float left_root, right_root;
	int roots; 
};

quad_results quad(float a, float b, float c);



float ilerp(float start, float end, float t);


struct Point { float x, y; };
float distance(const Point &P1, const Point &P2);


struct Point3D { float x, y, z; };
float inner(const Point3D &P1, const Point3D &P2);

struct Plane { Point3D abc; float d; };
float point_plane_distance(const Plane &pl, const Point3D &pt);

Point3D bezier(float t, const Point3D &p1, const Point3D &p2,
						const Point3D &p3, const Point3D &p4);






