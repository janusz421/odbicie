#include <iostream>
#include <math.h>
#include "Vector.h"
#include "Point.h"

int main() {
	Point *a = new Point(1, 1, 1);
	Point *b = new Point(-2, 0, 0);
	Vector *vecA = new Vector(a);
	Vector *vecB = new Vector(b);
	//Vector *vecC = *vecA + *vecB;
	//*a = *a + *b;
	return 0;
}
