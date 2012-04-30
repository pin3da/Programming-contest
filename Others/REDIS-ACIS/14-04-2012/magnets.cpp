using namespace std;
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cstdio>
#include<cstdlib>
#include<cmath>

#define MAX_double 1.79769e+308
#define FILE_IN "magnets"

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
	return (x <= y + tol) ? ( x+ tol < y) ? -1 : 0 : 1;
}

typedef pair<double, double > pdd;

int main(){
	freopen(FILE_IN ".in","r",stdin);
	string cad;
	set<char> myset;
	int pin=1;
	while(true){
		getline(cin,cad);
		if(cad=="END")break;
		myset.clear();
		pin=1;
		for(int i=0;i<cad.size();++i){
			if(!myset.insert(cad[i]).second && cad[i]!=' '){
				pin=0;
				break;
			}
		}
		if(pin)cout<<cad<<endl;
	}

	return 0;
}
