using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#define For(i,n) for(int i = 0; i<(n) ; ++i)

int dx[] = {-1,-1,0,0,1,1};
int dy[] = {-1,0,-1,1,1,0};

int dp[42][42][42];


int solve(int x,int y,int steps){
    if (steps == 0) return (x==20 and y ==20); 
    int ans = 0;
    if(dp[x][y][steps] != -1) return dp[x][y][steps];
    For(i,6){
        if(x+ dx[i] >= 0 and x+ dx[i] < 40 and y+ dy[i] >= 0 and y+ dy[i] < 40);
        ans +=  solve(x+ dx[i], y+ dy[i],steps -1);
    }
    return dp[x][y][steps] = ans;

}

int main(){
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        memset(dp,-1,sizeof(dp));
        cout<<solve(20,20,n)<<endl;
    }


    return 0;
}
