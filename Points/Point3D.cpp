#include "Point3D.h"
#include <iostream>
Point3D::Point3D(int x, int y, int z, char letter):Point2D(x, y), Z(z)
{
	this->letter = letter;
}

void Point3D::print_info()
{
	std::cout << letter << "("<< x << ";" << y << ";" << z << ")\n";
}


