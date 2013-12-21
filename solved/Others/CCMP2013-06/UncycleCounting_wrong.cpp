using namespace std;
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define D(x) cout<< #x " = "<<(x)<<endl

vector<int> cod,decode;
int n,m;
int dp[1<<15];

int valid(int i,int gap){
    int tmp = i;
    while(tmp >= 0){
        if(!decode[tmp]) return false;
        tmp -= gap;
    }
    tmp = i;
    while(tmp < n){
        if(!decode[tmp]) return false;
        tmp += gap;
    }
    return true;
}

int marcar(int mask, int start, int gap){
    for(int i = 0; i < cod.size(); i++){
        int diff = fabs(cod[i] - start);
        if((diff % gap == 0) && ((mask & (1 << i)) != 0))
            mask ^= (1 << i);
    }
    return mask;
}

int solve(int state){
    int bits_on = __builtin_popcount(state);
    if(bits_on == 0) return 0;
    if(bits_on == 1) return 1;
    
    if(dp[state] != -1) return dp[state];
    
    int index = __builtin_ctz(state);
    D(state);
    int ans = 1<<30;
    for(int i = index + 1; i < cod.size(); ++i){
        if((state & (1 << i)) == 0) continue;
        
        int gap = cod[i] - cod[index];
        if(!valid(cod[i], gap)) continue;
        int mask = marcar(state, cod[i], gap);
        ans = min(ans, 1 + solve(mask));
    }
    
    ans = min(__builtin_popcount(state), ans);
    return dp[state] = ans;
}

int main(){
    while(cin>>n>>m){
        int t;
        cod.assign(m+1,0);
        decode.assign(n,0);
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i< m; ++i){
            cin>>t;
            cod[i] = t;
            decode[t] = 1;
        }
        cout<<solve((1<<m)-1)<<endl;
    }
    return 0;

}

