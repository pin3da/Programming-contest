using namespace std;
#include <bits/stdc++.h>

double cost(pair<int, int> &a, pair<int, int> &b) {
  double x = a.first - b.first;
  double y = a.second - b.second;
  return sqrt(x * x + y * y);
}

const int MN = (1 << 9) + 9;
double dp[MN][MN];

double go(vector<pair<int, int>> &p, int a, int b) {
  int i = max(a, b) + 1;
  if (dp[a][b] > 0) return dp[a][b];
  if (i == p.size() - 1) {
    return dp[a][b] = cost(p[a], p[i]) + cost(p[b], p[i]);
  }
  return dp[a][b] = min(cost(p[a], p[i]) + go(p, i, b), cost(p[b], p[i]) + go(p, a, i));
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>>  p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }

  for (int i = 0; i < MN; ++i) {
    for (int j = 0; j < MN; ++j) {
      dp[i][j] = -1;
    }
  }

  cout << fixed << setprecision(11) << go(p, 0, 0) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

  return 0;
}
