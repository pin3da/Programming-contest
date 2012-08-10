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

ull nums[MP];

int main(){
	set<ull> mio;
	ull i;
	for(i=0;i<=MP;++i){
		nums[i]=((i)*(i+1))/2;
	}
	Dbg D(((i)*(i+1))/2);
	
	int numcas;cin>>numcas;
	int cid=0;
	ull num,ans;
	while(numcas--){
		int i;
		cin>>num;
		ull tmp=sqrt(2*num+ (1/4)) - 1/2;
		if((tmp*(tmp+1))/2 > num)tmp--;
	
		cout<<"Case "<<++cid<<": "<<nums[tmp]<<" "<<num-nums[tmp]<<endl;
	}
	return 0;
}
