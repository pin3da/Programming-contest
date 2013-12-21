using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MP 501

vector<int> value;
vector<int> sum;

int f(int from, int to){
    if(from <= 0) return sum[to];
    return sum[to] - sum[from-1];
}

int dpcost[MP][MP];

int cost(int i,int j){
    int &ans = dpcost[i][j];
    if(ans != -1) return ans;
    ans = 0;
    for(int k = i; k < j; ++k)
        ans += value[k]*f(k+1,j);    
        
    return ans;
}

int dp[MP][MP];
int solve(int i, int j){
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = (1<<30);
    if(i == value.size()) return ans = 0;
    if(j == 0) return ans = cost(i,value.size()-1);
    if(i == value.size()-1) return ans = 0;
    for(int k = i+1; k < value.size(); ++k)
        ans = min(ans,solve(k,j-1) + cost(i,k-1));
    return ans;
}

int main(){ ___
    int n,m;
    while(cin>>n>>m and n+m){
        memset(dp,-1,sizeof dp);
        memset(dpcost,-1,sizeof dpcost);
        
        value.resize(n);
        sum.resize(n);
        for(int i = 0; i< n; ++i)
            cin>>value[i];
        sum[0] = value[0];
        for(int i = 1; i< n; ++i)
            sum[i] = sum[i-1]+value[i];
               
        cout<<solve(0,m)<<endl;
    }
    return 0;
}
