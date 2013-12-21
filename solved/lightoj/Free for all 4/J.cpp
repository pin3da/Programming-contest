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
const double pi2=acos(0);

typedef unsigned long long ull;

double fun(double t){
	return   sin(pow(t,pi2))/t  + log(t)*cos(pow(t,pi2))*pi2*pow(t,(pi2-1.0));
}

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	while(numcas--){
		double num;cin>>num;	
		Dbg D(fun(num));
		cout<<"Case "<<++cid<<": "<<((fun(num)>0)?"forward":"backward")<<endl;
	}
	return 0;
}
