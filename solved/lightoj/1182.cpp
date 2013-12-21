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


int main(){
	int numcas;cin>>numcas;
	int cid=0,n;
	while(numcas--){
		cin>>n;
		cout<<"Case "<<++cid<<": ";
		if(__builtin_popcount(n)%2==0)cout<<"even"<<endl;
		else cout<<"odd"<<endl;
	}
	return 0;
}
