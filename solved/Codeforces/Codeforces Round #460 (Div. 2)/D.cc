#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << to_string(h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif

typedef vector<vector<int>> graph;

bool cycle(graph &g, vector<int> &col, int node) {
  if (col[node] == 1) return true;
  if (col[node] == 2) return false;
  col[node] = 1;
  for (auto to : g[node]) {
    if (cycle(g, col, to))
      return true;
  }
  col[node] = 2;
  return false;
}


const int MN = 300000 + 100;
int dp[MN][30];

int go(graph &g, vector<int> &val, int node, int c) {
  if (dp[node][c] != -1) return dp[node][c];

  int ans = val[node] == c;
  int best = ans;
  for (auto to : g[node]) {
    best = max(best, go(g, val, to, c) + ans);
  }
  return dp[node][c] = best;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;
  vector<int> values(n);
  for (int i = 0; i < n; i++) {
    char t; cin >> t;
    values[i] = t - 'a';
  }

  graph g(n);
  int has_cycle = false;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    if (u == v) has_cycle = true;
  }

  if (has_cycle) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> color(n);
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      if (cycle(g, color, i)) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  memset(dp, -1, sizeof dp);
  int best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      best = max(best, go(g, values, i, j));
    }
  }
  cout << best << endl;

  return 0;
}
