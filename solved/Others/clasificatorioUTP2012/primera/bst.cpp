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

typedef unsigned long long ull;

int main(){
	int n;scanf("%d",&n);
	map<int,ull> all;
	map<int,ull>::iterator it,it2;
	ull t,ans,acum=0;scanf("%llu",&t);
	cout<<0<<endl;
	all[t]=0;
	For(i,n-1){
		scanf("%llu",&t);
		it=all.lower_bound(t);
		it2=all.upper_bound(t);
		it--;
		Dbg D(t);
		if(it!=all.end() && it2!=all.end())
			ans = max(it->second,it2->second);
		else if(it!=all.end())
			ans = it->second;
		else if(it2 != all.end())
			ans = it2->second;
		acum+=ans+1;
		//cout<<acum<<endl;
		printf("%llu\n",acum);
		all[t]= ans+1;
	}
	return 0;
}
