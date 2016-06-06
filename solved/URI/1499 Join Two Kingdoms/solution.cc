#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef vector<vector<int>> graph;


unordered_map<int, int> dp;

int go(graph &g, int node, int pi) {
  int st = node * g.size() + pi;
  if (dp.count(st))
    return dp[st];

  int best = 0;
  for (auto &to : g[node]) {
    if (to != pi)
      best = max(best, go(g, to, node) + 1);
  }
  return dp[st] = best;
}

long long get_sum(vector<long long> &arr, int from, int end) {
  long long ans = arr[end];
  if (from)
    ans -= arr[from - 1];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  cout << fixed << setprecision(3);
  dp.reserve(100000);
  while (cin >> n >> m) {
    graph g1(n), g2(m);
    int u, v;
    for (int i = 0; i + 1 < n; ++i) {
      cin >> u >> v; u--; v--;
      g1[u].emplace_back(v);
      g1[v].emplace_back(u);
    }
    for (int i = 0; i + 1 < m; ++i) {
      cin >> u >> v; u--; v--;
      g2[u].emplace_back(v);
      g2[v].emplace_back(u);
    }
    vector<int> d1(n); dp.clear();
    for (int i = 0; i < n; ++i)
      d1[i] = go(g1, i, i);

    vector<int> d2(m); dp.clear();
    for (int i = 0; i < m; ++i)
      d2[i] = go(g2, i, i);

    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    int best = max(d1.back(), d2.back());
    vector<long long> p2(m);
    for (int i = 0; i < m; ++i) {
      p2[i] = d2[i];
      if (i) p2[i] += p2[i - 1];
    }

    double ans = 0;
    double p = 1.0 / m;
    for (int i = 0; i < n; ++i) {
      int tar = best - d1[i] - 1;
      int idx = upper_bound(d2.begin(), d2.end(), tar) - d2.begin();
      ans += (idx * best) * p;
      ans += get_sum(p2, idx, m - 1) * p;
      ans += (d1[i] + 1.0) * (m - idx) * p;
    }
    ans /= double (n);
    cout << ans << endl;
  }
  return 0;
}
