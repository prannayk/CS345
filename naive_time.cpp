#include <iostream>
#include <LEDA/geo/circle.h>
#include <LEDA/geo/point.h>
#include <time.h>
using namespace std;
using leda::point;
using leda::circle;

int main(){
	int n; float i,j;
	cin>>n; circle smallest;
	point ps[n];
	point p1;
	int size = n; clock_t sec = clock();
	while(n > 0){
		n--;
		cin>>i ; cin>>j;
		point p2 (i,j);
		ps[n] = p2; 
	}
	if (size  == 1) {
		cout << "Center of circle : " << ps[0] << " and radius is : " << 0 << endl; return 0;
	} else if (size == 2) {
		point p1((ps[0].to_vector() + ps[1].to_vector()) / 2);
		cout << "Center of circle : " << p1 << " and radius is  : " << ps[0].distance(p1) << endl; return 0;
	}
	int count;
	for (int i=0; i<size;i++){
		for (int j=i+1 ; j <size; j++){
			int flag = 0; 
			point center((ps[i].to_vector() + ps[j].to_vector())/2);
			circle cir(center, center.distance(ps[i]));
			for (int c=0; c < size ; c++ ) {
				if (cir.outside(ps[c]) && (c!=i) && (c!=j)) {
					flag++;
					break;
				}
			}
			if (flag == 0){if (smallest.radius() > cir.radius() || (smallest.radius() > 0) && (cir.radius() > 0))	smallest = cir;}
			for (int k=j+1; k<size; k++){
				circle cir(ps[i], ps[j], ps[k]);
				int flag = 0;
				for (int c = 0; c < size ; c++){
					if (cir.outside(ps[c]) && (c!=i) && (c!=j) && (c!=k)) {
						flag++;
						break;
					}
				}
				if (flag == 0) {if(smallest.radius() > cir.radius() || (smallest.radius() == 0) && (cir.radius() > 0))	smallest = cir;}
			}
		}
	}
	cout << (float)(clock() - sec) / CLOCKS_PER_SEC << endl; 
}
