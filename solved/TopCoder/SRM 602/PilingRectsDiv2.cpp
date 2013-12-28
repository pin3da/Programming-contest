using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

vector<int> x,y;
int lim;

int _dp[55][205][205];

int dp(int i, int X, int Y){
  if(_dp[i][X][Y] != -1) return _dp[i][X][Y] ;
  if(i == x.size()) {
      if(X == 201 or Y == 201) return _dp[i][X][Y] =  -1;
      return _dp[i][X][Y] =  0;
  }

  int nx = min(X, x[i]);
  int ny = min(Y, y[i]);

  int ans = -1;
  if(nx*ny >= lim){
    if(dp(i+1,nx,ny) != -1)
      ans =  max(ans,1+dp(i+1,nx,ny));
  }

  nx = min(Y, x[i]);
  ny = min(X, y[i]);

  if(nx*ny >= lim){
    if(dp(i+1,nx,ny) != -1)
      ans =  max(ans,1+dp(i+1,nx,ny));
  }
  ans = max(ans, dp(i+1,X,Y));

  return _dp[i][X][Y] = ans;
}

class PilingRectsDiv2 {
  public:
    int getmax(vector <int> X, vector <int> Y, int limit) {
      x = X;
      y = Y;
      lim = limit;
      memset(_dp,-1,sizeof _dp);
      return dp(0,201,201);
    }
};
