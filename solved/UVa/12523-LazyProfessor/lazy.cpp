using namespace std;
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define D(x) cout<< #x " = "<<(x)<<endl

int n,s;
int grades[21][101];
int weights[21][2];
int sol[21];
long long dp[21][101];


long long solve(int exam, int remain){
    if(remain < 0) return -(1e9);
    if(exam == n)  return 0;

    if(dp[exam][remain] != -1) return dp[exam][remain];
    long long ans = -(1e9);
    int tmp = 0;
    for(int j = 0; j< s;++j)
            tmp += grades[exam][j];
  
    for(int i = weights[exam][0]  ; i<= weights[exam][1]; ++i)
        ans = max(ans,tmp*i + solve(exam+1 , remain - i));
        
    return dp[exam][remain] = ans;
    
}

int main(){
    while(cin>>s>>n and n+s){
        for(int i = 0; i< s; ++i)
            for(int j = 0; j< n; ++j)
                cin>>grades[j][i];
                    
        for(int i = 0; i< n;++i)
            cin>>weights[i][0]>>weights[i][1];
        
        memset(dp,-1,sizeof dp);
        double tt = solve(0,100)/(double)s;
        int ans = (int)round(tt);
        printf("%d.%02d\n", ans/100, ans%100);
    }
    return 0;
}

