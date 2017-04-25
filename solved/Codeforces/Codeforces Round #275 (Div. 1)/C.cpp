// http://codeforces.com/contest/482/problem/C

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


const int MN = 55, MM = 20;
long long dp[(1 << MM) + 2];
double ans[(1 << MM) + 2];
string data[MN];

int s, n;

int main() { ___

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> data[i];

  s = data[0].size();

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int same = 0;
      for (int k = 0; k < s; ++k)
        if (data[i][k] == data[j][k])
          same |= 1 << k;
      dp[same] = (1LL << j) | (dp[same] | 1LL << i);
    }
  }

  for (int mask = (1 << s) - 1; mask >= 0; --mask)
    for (int i = 0; i < s; ++i)
      if ((mask >> i) & 1)
        dp[mask ^ (1 << i)] |= dp[mask];


  for (int mask = (1 << s) - 1; mask >= 0; --mask) {
    if (dp[mask] == 0LL)
      ans[mask] = 0;
    else {
      ans[mask] = 0;
      double events = s - __builtin_popcount(mask);
      for (int i = 0; i < s; ++i) {
        if (!((mask >> i) & 1)) {
          ans[mask] += ans[mask | 1 << i] * (double) __builtin_popcountll(dp[mask | 1 << i]) / (double)__builtin_popcountll(dp[mask]);
        }
      }
      ans[mask] = 1.0 + ans[mask] / events;
      if (ans[mask] != ans[mask]) {
        D(mask);
        exit(0);
      }
    }
  }

  cout << setprecision(15) << ans[0] << endl;

  return 0;
}