using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<limits>
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

const double pi=acos(-1);

typedef unsigned long long ull;

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	ull a,b,tmp;
	while(numcas--){
		ull num;cin>>num;
		cout<<"Case "<<++cid<<": ";
		if(num&1)
			cout<<"Impossible"<<endl;
		else{
			ull i=1;
			for(i=2;(num%i!=0) or (num/i)%2==0;i<<=1);
			cout<<num/i<<" "<<i<<endl;
		}
		
	}
	return 0;
}
