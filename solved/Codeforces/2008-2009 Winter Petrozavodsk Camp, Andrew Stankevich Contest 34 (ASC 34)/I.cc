#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

typedef vector<vector<int> > graph;


map<pair<int, int> , int> dp;
int go(graph &g, int node, int pi) {
  int ans  = 0;
  pair<int, int> state(node, pi);
  if (dp.count(state)) return dp[state];

  for (size_t i = 0; i < g[node].size(); ++i) {
    int to = g[node][i];
    if (to != pi) {
      ans += go(g, to, node);
    }
  }

  if (g[node].size() == 1 && node != pi) {
    ans++;
  }
  return dp[state] = ans;
}

int go2(graph &g, int node, int pi) {
  int ans  = 0;
  pair<int, int> state(node, pi);
  if (dp.count(state)) return dp[state];

  for (size_t i = 0; i < g[node].size(); ++i) {
    int to = g[node][i];
    if (to != pi) {
      ans += go2(g, to, node);
    }
  }
  if (g[node].size()) {
    if (node != pi)
      ans += max<int>(0, g[node].size() - 2);
    else
      ans += max<int>(1, g[node].size() - 1);
  }
  return dp[state] = ans;
}


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
  freopen("tour.in", "r", stdin);
  freopen("tour.out", "w", stdout);
#endif

  int n;
  while (cin >> n) {
    graph g(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    dp.clear();
    long long best = n * n;
    for (int i = 0; i < 1; ++i) {
      int t = go(g, i, i);
      if (t & 1) t++;
      best = min<long long>(best, t - 2);
    }
    cout <<  best << endl;

    /*
    dp.clear();
    long long best2 = n * n;
    for (int i = 0; i < n; ++i) {
      best2 = min<long long>(best2, go2(g, i, i));
    }
    assert(best == best2);
    */
  }
  return 0;
}
