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
  vector<int> degree(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < (n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    degree[u]++;
    degree[v]++;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> seen(n), inc(n);
  deque<int> q;

  for (int i = 0; i < n; i++) {
    if (degree[i] == 1) {
      q.push_back(i);
      seen[i] = 1;
    }
  }

  int ok = true;
  int cur = 1;
  while (!q.empty() && k > 0) {
    set<int> nxt;
    for (auto node : q) {
      for (auto to : g[node]) {
        if (seen[to] && (seen[to] < seen[node])) continue;
        if (seen[to] && (seen[to] == seen[node])) {
          ok = false;
          continue;
        }
        nxt.insert(to);
        inc[to]++;
      }
    }


    for (auto it : nxt) {
      if (inc[it] < 3) {
        ok = false;
        break;
      }
      seen[it] = cur + 1;
    }
    if (!ok) break;
    q.clear();
    for (auto it : nxt) q.push_back(it);
    k--;
    cur++;
    if (k == 0) ok &= (q.size() == 1);
  }

  if (k > 0) ok = false;
  for (auto it : seen) if (!it) ok = false;

  puts(ok ? "Yes" : "No");

  return 0;
}
