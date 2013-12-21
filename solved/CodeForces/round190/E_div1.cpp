using namespace std;
#include<bits/stdc++.h>
#define MN 4004
#define MK 808

int n,k;
int un[MN][MN];
int ii[MN][MN];

void fill_ii(){
  memset(ii, 0, sizeof ii);
  ii[0][0] = un[0][0];
  for(int i = 1; i < n; ++i){
    ii[i][0] += (ii[i-1][0] + un[i][0]);
    ii[0][i] += (ii[0][i-1] + un[0][i]);
  }
  for(int i = 1; i < n; ++i){
    for(int j = 1; j < n; ++j ){
      ii[i][j] += un[i][j];
      ii[i][j] += ii[i-1][j-1];
      ii[i][j] -= (ii[i][j-1] + ii[j-1][i]);
    }
  }
}

long long cost(int i, int j, int p, int q){
  long long ans = ii[p][q];
  if(i > 0) ans -= ii[i-1][j];
  if(j > 0) ans -= ii[i][j-1];
  if(i > 0 and j > 0) ans += ii[i-1][j-1];
  return ans;
}

long long cost(int i, int p){
  return cost(i,i,p,p);
}

long long me[MN][MK];

long long  dp(int i,int r){
  if(me[i][r] != -1) return me[i][r];
  if(i == n) return me[i][r] = ((r == 0) ? 0 : (1<<30));

  long long ans = (1<<30);
  if(r == 1) ans = cost(i,n - 1);
  for(int j = i; j < n; ++j){
    ans = min(ans, cost(i,j) + dp(j+1,r-1));
  }
  return me[i][r] = ans;
}

int main(){
  while(cin>>n>>k){
    for(int i = 0 ; i < n; ++i)
      for(int j = 0; j < n; ++j)
        cin>>un[i][j];
    fill_ii();
    memset(me, -1, sizeof me);
    cout<<dp(0,k)<<'\n';
  }
  return 0;
}
