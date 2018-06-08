#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<vector<int>> color_positions(k);
  for (int i = 0; i < n; i++) {
    int color;
    cin >> color;
    color_positions[color - 1].push_back(i);
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<vector<int>> dist(n, vector<int> (k));

  for (int c = 0; c < k; c++) {
    vector<int> best(n, n + 100);
    queue<int> q;
    for (auto p : color_positions[c]) {
      best[p] = 0;
      q.push(p);
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto to : g[node]) {
        if (best[node] + 1 < best[to]) {
          best[to] = best[node] + 1;
          q.push(to);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      dist[i][c] = best[i];
    }
  }

  for (int i = 0; i < n; i++) {
    sort(dist[i].begin(), dist[i].end());
    int ans = 0;
    for (int j = 0; j < s; j++)
      ans += dist[i][j];
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}
