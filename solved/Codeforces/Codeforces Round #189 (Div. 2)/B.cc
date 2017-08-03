#include <bits/stdc++.h>

using namespace std;

struct interval {
  int a, b;
  interval(int x, int y) : a(x), b(y) {}

  bool inside(const interval &o) {
    return (a > o.a && a < o.b) || (b > o.a && b < o.b);
  }
};

bool check(vector<vector<int>> &g, int a, int b) {
  const int inf = g.size() + 100;
  vector<int> dist(g.size(), inf);
  dist[a] = 0;
  deque<int> q;
  q.push_back(a);
  while (!q.empty()) {
    int next = q.front(); q.pop_front();
    for (auto to : g[next]) {
      if (dist[to] == inf) {
        dist[to] = dist[next] + 1;
        q.push_back(to);
      }
    }
  }
  return dist[b] != inf;
}

int main() {
  int n; cin >> n;
  vector<interval> all;
  vector<vector<int>> g(n);
  while (n--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      int s = all.size();
      all.emplace_back(a, b);
      for (int i = 0; i < s; i++) {
        if (all[i].inside(all[s])) g[i].push_back(s);
        if (all[s].inside(all[i])) g[s].push_back(i);
      }
    } else {
      puts(check(g, a - 1, b - 1) ? "YES" : "NO");
    }
  }
  return 0;
}
