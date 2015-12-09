#include "Point.h"

void Point::setPoint(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

void Point::setZ(int z)
{
	this->z = z;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

int Point::getZ()
{
	return z;
}