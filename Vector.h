class Point;

class Vector {
public:
	Vector(Point *end);

	Vector* operator+(Vector a);

	float getXLength();
	float getYLength();
	float getZLength();
	void setXLength(float x);
	void setYLength(float y);
	void setZLength(float z);
private:
	Point *end;
	double force;
};