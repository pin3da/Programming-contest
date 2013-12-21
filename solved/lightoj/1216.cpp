using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

const double pi=acos(-1);

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	double r1,r2,h,p;
	
	while(numcas--){
		cin>>r1>>r2>>h>>p;
		double r3 = (r1-r2)*p/h;
		r3+=r2;
		double ans = (p*pi*(r2*r2 + r3*r3 + r2*r3))/3.0;
		cout<<fixed<<"Case "<<++cid<<": "<<ans<<endl;
	}
	return 0;
}
