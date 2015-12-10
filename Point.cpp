#include "Point.h"
#include "Vector.h"

void Point::setPoint(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::setX(float x)
{
	this->x = x;
}

void Point::setY(float y)
{
	this->y = y;
}

void Point::setZ(float z)
{
	this->z = z;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

float Point::getZ()
{
	return z;
}

void Point::movePoint(Vector moveVector)
{
	this->x += moveVector.getXLength();
	this->y += moveVector.getYLength();
	this->z += moveVector.getZLength();
}
