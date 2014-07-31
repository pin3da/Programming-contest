using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MN  = 10001;
const int MP  = 101;
const int inf = 1111111;

double dp[MP][MN];
int va[MP];
double pr[MP];

int n;
double treshold;

void solve() {
  cin>>treshold;
  cin>>n;
  int mmax = 0;
  for (int i = 0; i < n; ++i) {
    cin>>va[i];
    mmax += va[i];
    cin>>pr[i];
  }

  for (int i = 0; i < MN; ++i)
    dp[n][i] = 1;
  dp[n][0] = 0;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < MN; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (j - va[i] >= 0)
        dp[i][j] = min(dp[i][j], dp[i + 1][j - va[i]] + (1.0 - dp[i + 1][j - va[i]]) * pr[i]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= mmax; ++i) {
    if (dp[0][i] < treshold)
      ans = i;
  }
  cout<<ans<<endl;

}

int main() { ___

  int tc;
  cin>>tc;
  for (int i = 0; i < tc; ++i) {
    cout<<"Case "<<(i+1)<<": ";
    solve();
  }
  return 0;
}
