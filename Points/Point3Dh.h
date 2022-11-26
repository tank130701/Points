#pragma once
#include "Point2D.h"
#include "H.h"
#include "Z.h"
class Point3Dh : Point2D, Z, H
{
public:
	Point3Dh(char letter, int x, int y, int z, double h);
	void print_info();
};

