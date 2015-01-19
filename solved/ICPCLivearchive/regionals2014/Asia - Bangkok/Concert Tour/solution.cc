#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli dp[111][110];
lli profit[110][60];
lli cost[110][110];

int M, C;

lli f(lli m, lli c) {
  if(dp[m][c] == -1) {
    if(m == M)
      return dp[m][c] = 0;

    lli mmax = -1;
    for(lli ci=0; ci<C; ci++) {
      mmax = max(mmax, profit[c][m] - ( (m!=M-1)?cost[c][ci]:0 ) + f(m+1, ci));
    }
    return dp[m][c] = mmax;
  }
  else
    return dp[m][c];
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    memset(dp, -1, sizeof dp);

    cin >> C >> M;

    for(int i=0; i<C; i++) {
      for(int j=0; j<M; j++)
        cin >> profit[i][j];
    }

    for(int i=0; i<C; i++) {
      for(int j=0; j<C; j++)
        cin >> cost[i][j];
    }

    lli mmax = -1;
    for(int c=0; c<C; c++)
      mmax = max(mmax, f(0, c));

    cout << mmax << endl;
  }
}
