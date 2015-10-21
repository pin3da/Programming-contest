using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

typedef bitset<5005> bitmask;

void dfs(vector<vector<int> > &g, vector<bool> &vi, int node,
         vector<bitmask> &r) {

  if (vi[node])
    return;

  for (int i = 0; i < g[node].size(); ++i) {
    dfs(g, vi, g[node][i], r);
    r[node] |= r[g[node][i]];
  }
  r[node][node] = 1;
  vi[node] = true;
}

int tid[5005];

bool cmp(const int a, const int b) {
  return tid[a] < tid[b];
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  int u, v;
  vector<int> in(n);
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    in[v]++;
  }
  vector<bitmask> r(n);
  vector<bool> vi(n);
  vector<pair<int, int> > ans;

  deque<int> q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      q.push_back(i);
      dfs(g, vi, i, r);
    }
  }

  int t = 0;
  while (!q.empty()) {
    int node = q.front();q.pop_front();
    tid[node] = t++;
    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i];
      in[to]--;
      if (in[to] == 0)
        q.push_back(to);
    }
  }

  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end(), cmp);
    bitmask cur;
    for (int j = 0; j < g[i].size(); ++j) {
      int to = g[i][j];
      if (!cur[to]) ans.push_back(make_pair(i, to));
      cur |= r[to];
    }
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
