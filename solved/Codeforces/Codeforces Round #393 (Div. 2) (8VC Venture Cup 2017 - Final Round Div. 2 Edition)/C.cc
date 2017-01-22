#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


typedef vector<vector<int>> graph;

void paint(graph &g, vector<int> &c, int node, int t) {
  if (c[node] == -1) {
    c[node] = t;
    for (auto to: g[node])
      paint(g, c, to, t);
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n;
  graph g(n);
  for (int i = 0; i < n; ++i) {
    int to;
    cin >> to;
    g[i].push_back(to - 1);
  }

  vector<int> color(n, -1);

  int cycles = 0;
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1) {
      paint(g, color, i, cycles);
      cycles++;
    }
  }

  vector<int> b(n);
  for (auto &i: b) cin >> i;
  int any = accumulate(b.begin(), b.end(), 0);

  int ans = 0;
  if (cycles > 1) {
    ans = cycles;
  }
  if (!(any & 1))
    ans++;
  cout << ans << endl;

  return 0;
}
