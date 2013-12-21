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
	int t;cin>>t;
	for(int tid=1;tid<=t;++tid){
		int k;cin>>k;
		vector<int> todos(k);
		int mmin = 0;
		For(i,k){
			cin>>todos[i];
			mmin = max(mmin,todos[i]);
		}
		cout<<"Caso "<<tid<<": "<<(k+1)<<" "<<(mmin+1)<<endl;
	}
	return 0;
}
