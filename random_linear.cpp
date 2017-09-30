#include <iostream>
#include <LEDA/geo/circle.h>
#include <LEDA/geo/point.h>
#include <LEDA/geo/line.h>

using namepsace std;
using leda::point;
using leda::circle;
using leda::line ;

int main(){
	int n,i,j;
	cin>>n;
	point ps[n];
	point p1;
	int size = n;
	while(n > 0){
		n--;
		cin>>i ; cin>>j;
		point p1 (i,j);
		ps[n] = p1;  
	}
	circle c;
	if (size  == 1) {
		cout << "Center of circle : " << ps[0] << " and radius is : " << 0 << endl;
		return ; 
	} else {
		point p1((ps[0].to_vector() + ps[1].to_vector()) / 2);
		circle c1(p1,ps[0].distance(p1));
	}
	int i = 2;
	while ( i < size ) {
		if (c.outside(ps[i])){
			int far = 0;
			double dist = ps[0].distance(ps[i]);
			for (int j=1; j<i ; j++){
				distij = ps[i].distance(ps[j]);
				if (distij > dist){
					far = j;
					dist = distij;
				}
			}
			line l(ps[i],ps[far]);
			circle c(ps[i],ps[far],ps[far]);
			int p1 = i, p2 = far , p3 = far;
			for (int j=1; j<i; j++){
				if (c.outside(ps[j])){
					line l1(ps[i],ps[j]);
					double angle = l.angle(l,l1);
					if (angle > 0)	p2 = j;
					else if (angle < 0 )	p3 = j;
				}
				circle c2(ps[p1],ps[p2],ps[p3]);
				c = c2;
			}
		}
		i++;
	}
	return 0;
}
