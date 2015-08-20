using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 50005;
struct edge{
  int from, to;
  long long c;
  edge() {}
  edge(int a, int b, long long d) : from(a), to(b), c(d) {}
};

long long dp[MN], dp1[MN];

long long ce(vector<vector<edge>> &g, int x) {
  if (x == g.size() - 1)
    return 0;

  if (dp1[x] != -1)
    return dp1[x];

  long long ans = 0;
  for (int i = 0; i < g[x].size(); ++i)
    ans = max(ans, ce(g, g[x][i].to) + g[x][i].c);
  return dp1[x] = ans;
}

long long ue(vector<vector<edge>> &g, int x) {
  if (x == g.size() - 1)
    return 0;

  if (dp[x] != -1)
    return dp[x];

  long long ans = 0;
  if (g[x].size())
    ans += ue(g, g[x][0].to);
  for (int i = 1; i < g[x].size(); ++i) {
    ans += (g[x][i].c + ce(g, g[x][i].to)) != (g[x][i - 1].c + ce(g, g[x][i - 1].to));
    ans += ue(g, g[x][i].to);
  }

  return dp[x] = ans;
}


void solve(int n, int m) {
  vector<vector<edge>> g(n);
  vector<edge> edges;
  vector<int> in(n);
  int u, v, c;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    u--; v--;
    edges.push_back(edge(u, v, c));
    g[u].push_back(edge(u, v, c));
    in[v]++;
  }

  vector<long long> ub(n), cb(n);
  deque<int> q;
  for (int i = 0; i < n; ++i)
    if (in[i] == 0) {
      q.push_back(i);
    }

  while (!q.empty()) {
    int node = q.front(); q.pop_front();
    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i].to;
      if (cb[to] != 0 && (cb[node] + g[node][i].c) != cb[to])
        ub[to]++;
      ub[to] += ub[node];
      cb[to] = max(cb[to], cb[node] + g[node][i].c);
      in[to]--;
      if (in[to] == 0)
        q.push_back(to);
    }
  }

  memset(dp, -1, sizeof dp);
  memset(dp1, -1, sizeof dp1);

  for (int i = 0; i < n; ++i) {
    if (ub[i] > 0 && ue(g, i) > 0) {
      cout << "No solution" << endl;
      return;
    }
  }

  vector<pair<int, long long>> ans;
  for (int i = 0; i < edges.size(); ++i) {
    int u = edges[i].from, v = edges[i].to, c = edges[i].c;
    if (ub[u] == 0 && ub[v] > 0) {
      long long val = cb[n - 1] - cb[u] - ce(g, v) - c;
      if (val > 0) {
        ans.push_back(make_pair(i + 1, val));
      }
    }
  }

  cout << ans.size() << " " << cb[n - 1] << endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << endl;


}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m, cn = 1;
  while (cin >> n >> m && (n + m)) {
    cout << "Case " << cn << ": ";
    solve(n, m);
    cn++;
  }
  return 0;
}
