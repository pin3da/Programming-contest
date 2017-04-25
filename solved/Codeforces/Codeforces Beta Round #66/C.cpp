// http://codeforces.com/contest/73/problem/C

using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>

int C[26][26];
string cad;
int dp[105][30][105];

int solve(int index,int ant, int cambios){
    if(index == cad.size()) return 0;
    if(dp[index][ant][cambios] != -1) return dp[index][ant][cambios];
    int ans = ((index==0)? 0 : C[ant][cad[index]-'a']) + solve(index + 1, cad[index]-'a', cambios) ;     
    if(cambios==0) return dp[index][ant][cambios] = ans;
    for(int i = 0; i< 26; ++i)
        ans = max(ans, ((index==0)?0: C[ant][i]) + solve(index + 1, i, cambios - (i != cad[index] - 'a')) );
    
    return dp[index][ant][cambios] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    memset(C,0,sizeof(C));
    cin>>cad;
    int k;cin>>k;
    int n;cin>>n;
    for(int i = 0; i< n; ++i){
        char a,b;cin>>a>>b;
        int cost; cin>>cost;
        C[a-'a'][b-'a'] = cost;
    }
    cout<<solve(0,0,k)<<endl;
    return 0;
}