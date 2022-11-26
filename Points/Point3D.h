#pragma once
#include "Point2D.h"
#include "Z.h"
class Point3D : public Point2D, Z
{
public:
	Point3D(int x, int y, int z, char letter);
	void print_info();
};

