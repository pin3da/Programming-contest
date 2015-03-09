using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#define NS -2 // means No solution

struct tank{
    int ox,ni,we;
    tank(){}
};

vector<tank> A;
int dp[1010][25][81];

int solve(int index,int oxygen,int nitrogen){
    if(index == A.size()) return (oxygen + nitrogen == 0)? 0 : NS;
    if(dp[index][oxygen][nitrogen] != -1) return dp[index][oxygen][nitrogen];
    int a = solve(index +1, oxygen, nitrogen);
    int b =  solve(index +1, max(0,oxygen - A[index].ox ), max(0,nitrogen - A[index].ni) );
    if(a == NS and b == NS) return dp[index][oxygen][nitrogen] = NS;
    if(a != NS and b != NS) return dp[index][oxygen][nitrogen] = min(a,b + A[index].we);
    if(a == NS) return dp[index][oxygen][nitrogen] = b + A[index].we;
    return dp[index][oxygen][nitrogen] = a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;cin>>tc;
    while(tc--){
        memset(dp,-1,sizeof(dp));
        int oxygen,nitrogen;
        cin>>oxygen>>nitrogen;
        int tanks;cin>>tanks;
        A = vector<tank>(tanks);
        for(int i = 0; i< tanks;++i) cin>>A[i].ox>>A[i].ni>>A[i].we;
        cout<<solve(0,oxygen,nitrogen)<<endl;
    }

    return 0;
}
