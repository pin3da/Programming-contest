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

const double pi=acos(-1);

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	cout<< fixed;cout.precision(10);
	while(numcas--){
		double R,n;cin>>R>>n;
		cout<<"Case "<<++cid<<": "<<sin(pi/n)*R/(sin(pi/n) + 1)<<endl;
	}
	return 0;
}
