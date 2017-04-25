// http://codeforces.com/contest/615/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n, int m) {
  vector<int> dp(n);
  vector<vector<int>> g(n);
  vector<int> pi(n);
  vector<int> in(n), out(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    if (v < u) swap(u, v);
    g[u].push_back(v);
    out[u]++;
    out[v]++;
    in[v]++;
  }
  deque<int> q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) q.push_back(i);
  }

  vector<int> depth(n, 1);
  long long ans = 0;
  while (!q.empty()) {
    int cur = q.front();q.pop_front();
    ans = max(((long long) out[cur]) * depth[cur], ans);
    for (int i = 0; i < g[cur].size(); ++i) {
      int to = g[cur][i];
      depth[to] = max(depth[to], depth[cur] + 1);
      in[to]--;
      if (in[to] == 0) q.push_back(to);
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) solve(n, m);
  return 0;
}
