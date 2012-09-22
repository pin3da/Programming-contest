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
#define Dbg if(1)
#define MP 17

typedef unsigned int uint;

int pri[MP][MP];
int dp[MP][1<<MP];
int pos[1<<MP];
int N;

uint next_popcount(uint n){
	uint c = (n & -n);
	uint r = n+c;
	return (((r ^ n) >> 2) / c) | r;
}

void gen_pos(){
	For(i,MP)
		pos[1<<i]=i+1;
}

void solve(){
	for(int i=1;i<=N;++i)dp[1][1<<(i-1)] = pri[1][i];
	uint top = 1<<N;
	for (int i = 2; i <= N; ++i) {
		uint subset = (1<<i)-1;
		for(uint j=subset;j < top;j = next_popcount(j)){
			subset = j;
			int max=0;
			while(subset != 0){
				uint w = subset & -subset;
				int curr = pri[i][pos[w]] + dp[i-1][j & ~w];
				if(curr > max)max=curr;
				subset &= ~w;
			}
			dp[i][j] = max;
		}
	}
	
}

int main(){
	int numcas;cin>>numcas;
	int cid=0;
	gen_pos();
	while(numcas--){
		cin>>N;
		for(int i=1;i<=N;++i)
			for(int j=1; j<=N;++j)
				cin>>pri[i][j];
		
		solve();
		
		cout<<"Case "<<++cid<<": "<<dp[N][(1<<N)-1]<<endl;
	}
	return 0;
}
