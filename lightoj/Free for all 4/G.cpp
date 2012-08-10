using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(0)
#define MAXNODES 1000
#define MP 1000000 
const double pi=acos(-1);

typedef unsigned long long ull;



int main(){
	int numcas;cin>>numcas;
	int cid=0;
	while(numcas--){
		double r,h,ans;
		cin>>r>>h;
		ans=pi*r*r*h;
		Dbg D(ans);
		printf("Case %d: %.2lf %.2lf\n",++cid,ans*(2.0/3.0),ans*(1.0/3.0));
	}
	return 0;
}
