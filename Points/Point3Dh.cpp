#include <iostream>
#include "Point3Dh.h"
#include "Point2D.h"
#include "Z.h"
#include "H.h"
Point3Dh::Point3Dh(char letter, int x, int y, int z, double h):Point2D(x,y),Z(z),H(h)
{
	if (h)
	{
		this->letter = letter;
		this->x = x / h;
		this->y = y / h;
		this->z = z / h;
	}
}

void Point3Dh::print_info()
{
	std::cout << letter << "(" << x << ";" << y << ";" << z << ")\n";
}

