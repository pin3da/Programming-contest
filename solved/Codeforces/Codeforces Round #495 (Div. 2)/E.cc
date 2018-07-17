#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, k;
  cin >> n >> k;
  vector<vector<pair<int, int>>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    deg[u]++; deg[v]++;
  }

  multiset<pair<int, int>> q;

  int bad = 0; // not a path
  int extra = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] > 2) bad++;
    if (deg[i] == 1) {
      q.insert({0, i});
      deg[i]++;
      extra++;
    }
  }

  n += extra;

  vector<bool> erased(n);

  int dist = 0;
  while (n > k || bad > 0) {
    int node = q.begin()->second;
    dist = q.begin()->first;
    q.erase(q.begin());
    n--;

    deg[node]--;

    if (deg[node] == 2) bad--;
    if (deg[node] > 1) continue;

    erased[node] = true;
    for (auto to : g[node]) {
      if (!erased[to.first]) q.insert({to.second + dist, to.first});
    }
  }

  cout << dist << endl;
  return 0;
}
