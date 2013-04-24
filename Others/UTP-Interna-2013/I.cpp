using namespace std;
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#define For(i,n) for(int i=0;i<(n);++i)
#define foreach(x,n) for(typeof (n).begin() x = (n).begin(); x!= (n).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<<#x " = "<<(x)<<endl
#define MP 10000

template <class T> string toStr(const T &x)
{ stringstream s;s<<x;return s.str();}
template <class T> int toInt(const T &x)
{ stringstream s; s<<x; int r; s>>r;return r;}

typedef long long int lli;

double dist(double a,double b,double c,double d){
	double m = a-c;
	double n = b-d;
	return sqrt(m*m + n*n);
}

int main(){	
	int n;
	while(cin>>n and n){
		double posx,posy;
		cin>>posx>>posy;
		double x,y,radio;
		double mdist = 1e30;
		int ans = 0;
		For(i,n){
			cin>>x>>y>>radio;
			double tt = dist(posx,posy,x,y) - radio;
			assert(tt>=0);
			if(tt < mdist){
				mdist = tt;
				ans = i+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
