using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MN = 100001;

vector<int> _next[MN];
double dp[MN];

int main() { ___

  for (int i = 2; i < MN; ++i)
    for (int j = 1; j*j <= i; ++j)
      if ((i % j) == 0) {
        _next[i].push_back(j);
        if (j != (i/j))
          _next[i].push_back(i/j);
      }

  for (int i = 2; i < MN; ++i) {
    dp[i] = 1.0;
    for (int j = 0; j < _next[i].size(); ++j)
      if (_next[i][j] != i)
        dp[i] += (dp[_next[i][j]] + 1);
    dp[i] = dp[i] / (double) (_next[i].size() - 1);
  }

  int tc;cin>>tc;
  int n;
  for (int i = 0; i < tc; ++i) {
    cin>>n;
    printf("Case %d: %.10lf\n", i + 1, dp[n]);
  }

  return 0;
}
