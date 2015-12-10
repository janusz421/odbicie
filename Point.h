class Vector;

class Point {
private:
	float x;
	float y;
	float z;

public:
	Point(float x, float y, float z) : x(x), y(y), z(z) {};
	void setPoint(float x, float y, float z);
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	float getX();
	float getY();
	float getZ();
	void movePoint(Vector moveVector);
};