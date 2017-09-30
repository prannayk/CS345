#include <iostream>
#include <LEDA/geo/circle.h>
#include <LEDA/geo/point.h>

using namespace std;
using leda::point;
using leda::circle;

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
	if (size  == 1) {
		cout << "Center of circle : " << ps[0] << " and radius is : " << 0 << endl;
	} else if (size == 2) {
		point p1((ps[0].to_vector() + ps[1].to_vector()) / 2);
		cout << "Center of circle : " << p1 << " and radius is  : " << ps[0].distance(p1) << endl;
	}
	for (int i=0; i<size;i++){
		for (int j=i+1 ; j <size; j++){
			for (int k=j+1; k<size; k++){
				circle cir(ps[i], ps[j], ps[k]);
				int flag = 0;
				for (int c = 0; c < size ; c++){
					if (cir.outside(ps[c])) {
						flag++;
						break;
					}
				}
				if (flag == 0) {
					cout << "Center of circle : " << cir.center() << " and radius is : " << cir.radius() << endl;
					return 0;
				}
			}
		}
	}
}
