using namespace std;
#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000
#define s(x) x*x

const double p2 = acos(0);

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	int a,b,c;
	while(numcas--){
		cin>>a>>b>>c;
		cout<<"Case "<<++cid<<": ";
		if( (s(a)+s(b))==s(c) or (s(a)+s(c))==s(b) or (s(c)+s(b))==s(a)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
