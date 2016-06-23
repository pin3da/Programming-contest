#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 300001 + 10;
bool removed[MN];
int sz[MN], ans[MN];

void dfs(vector<vector<int>> &g, int node, int pi) {
  sz[node] = 1;
  for (int i = 0; i < g[node].size(); ++i) {
    int to = g[node][i];
    if (to != pi && !removed[to]) {
      dfs(g, to, node);
      sz[node] += sz[to];
    }
  }
}

int find_center(vector<vector<int>> &g, int node) {
  dfs(g, node, -1);
  int cap = sz[node] / 2, pi = -1;
  while (true) {
    bool seen = false;
    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i];
      if (!removed[to] && to != pi && sz[to] > cap) {
        seen = true;
        pi = node;
        node = to;
        break;
      }
    }
    if (!seen)
      return node;
  }
}

vector<vector<int>> g2;
vector<int> pi;
int magic(vector<vector<int>> &g, int node, int depth) {
  int center = find_center(g, node);
  ans[center] = depth;
  removed[center] = true;
  for (int i = 0; i < g[center].size(); ++i) {
    int to = g[center][i];
    if (!removed[to]) {
      int other = magic(g, to, depth + 1);
      g2[center].push_back(other);
      pi[other] = center;
    }
  }
  return center;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, q;
  while (cin >> n >> q) {
    int p;
    vector<vector<int>> g(n);
    g2.assign(n, vector<int>());
    pi.assign(n, -1);
    vector<int> level(n);
    for (int i = 0; i < n - 1; ++i) {
      cin >> p;
      p--;
      g[p].push_back(i + 1);
      level[i + 1] = level[p] + 1;
      g[i + 1].push_back(p);
    }
    memset(removed, 0, sizeof removed);
    magic(g, 0, 0);
    while (q--) {
      cin >> p;
      p--;
      int start = level[p];
      while (pi[p] != -1 && level[pi[p]] > start) {
        p = pi[p];
      }
      cout << p + 1 << endl;
    }
    /*
    for (int i = 0; i < n; ++i) {
      for (auto & to: g2[i]) {
        cout << "from " << i + 1 << " to " << to + 1 << endl;
      }
    }
    */
  }
  return 0;
}
