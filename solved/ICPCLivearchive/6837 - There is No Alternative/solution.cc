using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

struct edge{
  int u, v, c;
  edge() {}
  bool operator < (const edge &o) const {
    if (c == o.c) {
      if (u == o.u)
        return v < o.v;
      return u < o.u;
    }
    return c < o.c;
  }
};

struct entry{
  int to, c, l;
  entry() {
    l = 1;
  }
  entry(int t, int cc) {
    to = t;
    c = cc;
    l = 1;
  }
};

const int MN = 555;
int p[MN];

int fs(int x) {
  return (p[x] == x) ? x : p[x] = fs(p[x]);
}

void join(int x, int y) {
  if (fs(x) < fs(y))
    p[fs(x)] = fs(y);
  else
    p[fs(y)] = fs(x);
}

bool dfs(vector<vector<entry>> &g, int cur, int &tar, int pi, int &ct) {
  if (cur == tar) {
    return true;
  }
  for (int i = 0; i < g[cur].size(); ++i) {
    if ((g[cur][i].to != pi) && dfs(g, g[cur][i].to, tar, cur, ct)) {
      if (g[cur][i].c == ct) {
        g[cur][i].l = 0;
        int v = g[cur][i].to;
        for (int j = 0; j < g[v].size(); ++j) {
          if (g[v][j].to == cur) {
            g[v][j].l = 0;
            return true;
          }
        }
        assert(0);
      }
      return true;
    }
  }
  return false;
}

int lc[MN];

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<edge> all(m);
    for (int i = 0; i < m; ++i) {
      cin >> all[i].u >> all[i].v >> all[i].c;
      all[i].u--;
      all[i].v--;
    }

    sort(all.begin(), all.end());
    memset(lc, -1, sizeof lc);

    for (int i = 0; i < n + 1; ++i) {
      p[i] = i;
    }
    set<pair<int, int>> uni;
    vector<vector<entry>> ng(n);
    for (int i = 0; i < m; ++i) {
      int u = all[i].u;
      int v = all[i].v;
      int c = all[i].c;
      if (fs(u) != fs(v)) {
        ng[u].push_back(entry(v, c));
        ng[v].push_back(entry(u, c));
        join(u, v);
        lc[fs(u)] = c;
      } else {
        if (lc[fs(u)] == c) {
         dfs(ng, u, v, -1, c);
        }
      }
    }

    // cout << "pasa" << endl;
    long long tot_edges = 0, sum = 0;
    for (int i = 0; i < ng.size(); ++i) {
      for (int j = 0; j < ng[i].size(); ++j) {
        if (ng[i][j].l) {
          tot_edges++;
          sum += ng[i][j].c;
        }
      }
    }
    // cout << uni.size() << endl;
    // for (const auto &it : uni) {
    //  cout << it.first << " = " << it.second << endl;
    // }
    // cout << endl;
    cout << tot_edges / 2 << " " << sum / 2 << endl;
  }
  return 0;
}

