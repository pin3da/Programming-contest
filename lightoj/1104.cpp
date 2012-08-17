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
#define Dbg if(0)
#define MAXNODES 1000

const double pi=acos(-1);



int main(){
	int numcas;cin>>numcas;
	int cid=0,days;
	while(numcas--){
		cin>>days;
		int ans=1;
		double acum=1;
		for(ans;(1.0-acum)<0.5;++ans){
			acum*=(days-ans)/(double)days;
			Dbg D(acum);
		}
		cout<<"Case "<<++cid<<": "<<--ans<<endl;
	}
	return 0;
}
