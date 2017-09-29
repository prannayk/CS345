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
