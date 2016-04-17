#include<bits/stdc++.h>

using namespace std;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 20;
int x[MN], y[MN], q[MN];

int n;
long long compute_cost(int mask, int w, int h) {
  long long cost = 0;
  for (int i = 0; i < n; ++i) {
    if ((mask >> i) & 1) {
      long long a = w * h,
                b = x[i] * y[i];
      cost += (a - b) * q[i];
    }
  }
  return cost;
}

long long dp[(1 << 15) + 100][20];

long long go(int mask, int k) {

  if (dp[mask][k] != -1)
    return dp[mask][k];

  if (k == 1) {
    int w = 0, h = 0;
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        w = max(w, x[i]);
        h = max(h, y[i]);
      }
    }
    return dp[mask][k] = compute_cost(mask, w, h);
  }

  long long best = 1LL << 60;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int nmask = 0;
      for (int l = 0; l < n; ++l) {
        if (((mask >> l) & 1) == 0) continue;
        if (x[l] <= x[i] && y[l] <= y[j]) {
          nmask |= (1 << l);
        }
      }
      best = min(best, compute_cost(nmask, x[i], y[j]) + go(mask ^ nmask, k - 1));
    }
  }
  return dp[mask][k] = best;
}

void solve(int k) {
  for (int i = 0; i < n; ++i)
    cin >> x[i] >> y[i] >> q[i];
  memset(dp, -1, sizeof dp);
  cout << go((1 << n) - 1, k) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int k;
  while (cin >> n >> k) {
    solve(k);
  }
  return 0;
}
