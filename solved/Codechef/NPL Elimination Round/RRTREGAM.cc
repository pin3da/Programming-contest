#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

typedef vector<vector<int>> graph;

const int MN = 1e5 + 100;
int grundy[MN];

void dfs(graph &g, int node, int pi) {
  for (auto to : g[node]) {
    if (to != pi) {
      grundy[to] = grundy[node] + 1;
      dfs(g, to, node);
    }
  }
}

void solve() {
  int n; cin >> n;
  vector<int> all(n);
  read(all);
  for (auto &it : all) it /= 2;

  graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--;v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  dfs(g, 0, 0);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int val = all[i];
    if (val & 1) {
      ans ^= grundy[i];
    }
  }
  puts(ans ? "Rachel" : "Ross");
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

