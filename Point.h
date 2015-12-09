
class Point {
private:
	int x;
	int y;
	int z;

public:
	Point(int x, int y, int z) : x(x), y(y), z(z) {};
	void setPoint(int x, int y, int z);
	void setX(int x);
	void setY(int y);
	void setZ(int z);
	int getX();
	int getY();
	int getZ();
};