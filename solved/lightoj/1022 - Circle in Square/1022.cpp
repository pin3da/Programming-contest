/*
Manuel Pineda,
+ 1e-9 for precision.
*/
using namespace std;
#include<iostream>
#include<cstdio>
#include<cmath>

const double pi = acos(-1);

int main(){
	int numcas;cin>>numcas;
	double r;
	int cas=0;
	while(numcas--){
		cin>>r;
		double a = (4-pi)*r*r;
		printf("Case %d: %.2lf\n",++cas, a+1e-9);
	}

}
