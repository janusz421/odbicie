#include <math.h>

class Vector {
public:
	Vector(Point *end) {
		this->end = end;
		force = sqrt(pow(this->end->getX(), 2) + pow(this->end->getY(), 2) + pow(this->end->getZ(), 2));
	};

	Vector* operator+(Vector a) {
		return new Vector(new Point(end->getX() + a.end->getX(), end->getY() + a.end->getY(), end->getZ() + a.end->getZ()));
	}

	int getXLength();
	int getYLength();
	int getZLength();
//private:
	Point *end;
	double force;
};