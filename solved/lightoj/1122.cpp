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
#define MAXNODES 1000

typedef long long int lli;

lli dp[11][11];
int nums[10];
int m,n;

lli fill_dp(int missing, int actual){
    if(dp[missing][actual]) return dp[missing][actual];
    if (missing == 0) return 1LL;
    vector<int> possible;
    
    for(int i=0;i<m;++i)
        if (actual==0) 
            possible.push_back(nums[i]);
        else if(fabs(actual-nums[i])<=2) 
            possible.push_back(nums[i]);
            
    lli ans = 0;
    foreach(x,possible)
        ans+= fill_dp(missing-1,(*x));
    
    //D(ans);D(actual);D(missing);
    dp[missing][actual]=ans;
    return ans;
}


int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
	    cin>>m>>n;
	    memset(dp,0,sizeof(dp));
	    memset(nums,0,sizeof(nums));
	    for(int i=0;i<m;++i)
	        cin>>nums[i];
		cout<<"Case "<<cid<<": "<<fill_dp(n,0)<<endl;
	}
	return 0;
}
