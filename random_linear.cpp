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
			point center((ps[i].to_vector() + ps[0].to_vector()) / 2);
			circle c2(center,center.distance(ps[0]));
			c = c2;
			for(int j=1; j < i; j++){
				if(c.outside(ps[j])){
					point center((ps[j].to_vector() + ps[i].to_vector()) / 2);
					circle c2(center, center.distance(ps[j]));
					c = c2;
					for (int k=0; k < i; k++){
						if (c.outside(ps[k])){
							circle c2(ps[i], ps[j], ps[k]);
							c = c2;
						}
					}
				}
			}
		}
		i++;
	}
	cout << "Center of circle : " << c.center() << " and radius is : "<< c.radius() << endl;
	return 0;
}
