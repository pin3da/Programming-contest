using namespace std;
#include <bits/stdc++.h>

const int inf = 1 << 30;

int dp[1 << 16];

int go(vector<int> &v, int mask) {

  if (dp[mask] != -1) return dp[mask];

  if (__builtin_popcount(mask) == 1) {
    for (int i = 0; i < v.size(); ++i) {
      if ((mask >> i) & 1)
        return dp[mask] = v[i];
    }
  }

  if (__builtin_popcount(mask) == 2) {
   for (int i = 0; i < v.size(); ++i) {
      if (((mask >> i) & 1) == 0) continue;
      for (int j = 0; j < v.size(); ++j) {
        if (i == j) continue;
        if (((mask >> j) & 1) == 0) continue;
        return dp[mask] = max(v[i], v[j]);
      }
    }
  }

  int best = inf;
  for (int i = 0; i < v.size(); ++i) {
    if (((mask >> i) & 1) == 0) continue;
    for (int j = 0; j < v.size(); ++j) {
      if (i == j) continue;
      if (((mask >> j) & 1) == 0) continue;

      int cost = max(v[i], v[j]);
      int nmask = (mask ^ (1 << i)) ^ (1 << j);

      int mmin = inf, min_i = -1;
      for (int k  = 0; k < v.size(); ++k) {
        if (((nmask >> k) & 1) == 0) {
          if (v[k] < mmin) {
            mmin = v[k];
            min_i = k;
          }
        }
      }

      cost += mmin + go(v, nmask | (1 << min_i));
      if (go(v, nmask | (1 << min_i)) < inf)
        best = min(best, cost);
    }
  }

  return dp[mask] = best;
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> vel(n);
    for (int i = 0; i < n; ++i) {
      cin >> vel[i];
    }

    int t = 1 << n;
    memset(dp, -1, sizeof dp);
    cout << go(vel, t - 1) << endl;
  }
  return 0;
}
