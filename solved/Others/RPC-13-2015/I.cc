using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 100001;

int p[MN];

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

void js(int x, int y) {
  p[fs(x)] = fs(y);
}

int q[MN];
int d[MN];
int c[MN];

pair<int, long long> bfs(vector<vector<int> > &g, int node, int col) {

  d[node] = 0;
  c[node] = col;
  int head = 0, tail = 1;
  q[head] = node;
  long long best = 0, id = node;
  while (head < tail) {
    int cur = q[head++];
    if (d[cur] > best) {
      best = d[cur];
      id = cur;
    }
    for (int i = 0; i < g[cur].size(); ++i) {
      int to = g[cur][i];
      if (c[to] != col) {
        c[to] = col;
        d[to] = d[cur] + 1;
        q[tail++] = to;
      }
    }
  }

  return make_pair(id, best);
}

int comp_dia(vector<vector<int> > &g, int node) {
  int a = bfs(g, node, node << 1).first;
  return bfs(g, a, node << 1 | 1).second;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) p[i] = i;

  vector<vector<int> > g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    js(u, v);
  }

  vector<int> roots(n);
  for (int i = 0; i < n; ++i) roots[i] = fs(i);
  sort(roots.begin(), roots.end());
  roots.resize(unique(roots.begin(), roots.end()) - roots.begin());

  vector<int> dia(roots.size());

  memset(c, -1, sizeof c);
  for (int i = 0; i < dia.size(); ++i) {
    dia[i] = comp_dia(g, roots[i]);
    // cout << dia[i] << " ";
  }
  // cout << endl;

  sort(dia.rbegin(), dia.rend());
  int best = dia[0];
  if (dia.size() > 1)
    best = max(best, ((dia[0] + 1) >> 1) + ((dia[1] + 1) >> 1) + 1);

  if (dia.size() > 2)
    best = max(best, ((dia[1] + 1) >> 1) + ((dia[2] + 1) >> 1) + 2);

  cout << best << endl;
  return 0;
}
