using namespace std;
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cstdio>
#include<cstdlib>
#include<cmath>

#define MAX_double 1.79769e+308
#define FILE_IN "pizza"

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
	return (x <= y + tol) ? ( x+ tol < y) ? -1 : 0 : 1;
}

typedef pair<double, double > pdd;

int main(){
	freopen(FILE_IN ".in","r",stdin);
	double pi = acos(-1);
	int numcas,id=1;
	double d,p;
	vector<pdd> vec;
	while(cin>>numcas && numcas){
		vec.clear();
		while(numcas--)	{
	      		cin>>d>>p;
			double tmp = (pi* (d*d/4))/p;
			pdd pa(tmp,d);
			vec.push_back(pa);
		}
		sort(vec.begin(),vec.end());
		cout<<"Menu "<<id++<<": "<<vec[vec.size()-1].second<<endl;
	}

	return 0;
}
