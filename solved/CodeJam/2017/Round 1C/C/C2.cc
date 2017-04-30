#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

double dp[100][100];

double go(vector<double> &p, int i, int k) {
  if (i == int(p.size())) return k == 0;
  if (k == 0) return 1.0;
  if (dp[i][k] > -0.5) return dp[i][k];
  double ans = (go(p, i + 1, k - 1) * p[i]) + (go(p, i + 1, k) * (1.0 - p[i]));
  return dp[i][k] = ans;
}

void clear_dp() {
  for (int j = 0; j < 100; ++j)
    for (int w = 0; w < 100; ++w)
      dp[j][w] = -1;
}

void solve() {
  int n, k; cin >> n >> k;
  double u; cin >> u;
  vector<double> a(n);
  for (auto &i : a) cin >> i;
  double max_iter = 123456 / 2;
  double step = u / max_iter;
  while (max_iter--) {
    double best = -1;
    int id = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] + step <= 1.0) {
        a[i] += step;
        clear_dp();
        if (best < go(a, 0, k)) {
          best = go(a, 0, k);
          id = i;
        }
        a[i] -= step;
      }
    }
    if (id == -1) break;
    a[id] += step;
  }

  clear_dp();
  printf("%.9lf\n", go(a, 0, k));
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
