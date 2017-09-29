#include <LEDA/geo/circle.h>
#include <LEDA/geo/point.h>
#include <iostream>

using namespace std;
using leda::circle;
using leda::point;

int main(){
	point p1(0,0), p2(2,4), p3(2,6);
	circle c (p1, p2, p3);
	cout << c.radius() <<endl;
	return 0;
}
