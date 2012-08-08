// No accepted yet.

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
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000
#define MP 31622770

const double pi=acos(-1);

int main(){

	int numcas;cin>>numcas;
	int cid=0;
	
	while(numcas--){
		int a,b,ans=0;cin>>a>>b;
			ans= ( ((b-1)/3)*2 + (b-1)%3) - (((a-2)/3)*2 + (a-2)%3);
		cout<<"Case "<<++cid<<": "<<ans<<endl;
	}
	return 0;
}
