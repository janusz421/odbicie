#include "Vector.h"
#include "Point.h"
#include "math.h"

Vector::Vector(Point *end) {
	this->end = end;
	force = sqrt(pow(this->end->getX(), 2) + pow(this->end->getY(), 2) + pow(this->end->getZ(), 2));
};

Vector * Vector::operator+(Vector a) {
	return new Vector(new Point(end->getX() + a.end->getX(), end->getY() + a.end->getY(), end->getZ() + a.end->getZ()));
}

float Vector::getXLength() {
	return end->getX();
}

float Vector::getYLength()
{
	return end->getY();
}

float Vector::getZLength()
{
	return end->getZ();
}

void Vector::setXLength(float x)
{
	end->setX(x);
}

void Vector::setYLength(float y)
{
	end->setY(y);
}

void Vector::setZLength(float z)
{
	end->setZ(z);
}
