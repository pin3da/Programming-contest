#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Edge {
  int from, to, id;
};

void GenAns(vector<vector<int>> &g, vector<vector<bool>> &ans,
            vector<bool> &cur, int k, int id) {
  if (int(ans.size()) == k) return;

  if (id == int(g.size())) {
    ans.push_back(cur);
    return;
  }


  if (g[id].size() == 0) {
    GenAns(g, ans, cur, k, id + 1);
  } else {

    cur[g[id][0]] = true;

    GenAns(g, ans, cur, k, id + 1);
    for (int i = 1; i < int(g[id].size()); i++) {
      cur[g[id][i - 1]] = false;
      cur[g[id][i]] = true;
      GenAns(g, ans, cur, k, id + 1);
    }
    cur[g[id].back()] = false;
    cur[g[id][0]] = true;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<Edge>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back({u, v, i});
    g[v].push_back({v, u, i});
  }

  vector<map<int, vector<int>>> dists(n);

  vector<int> d(n, n + 10);
  d[0] = 0;

  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto e : g[cur]) {
      dists[e.to][d[cur] + 1].push_back(e.id);  // save all incoming edges

      if (d[cur] + 1 < d[e.to]) {
        d[e.to] = d[cur] + 1;
        q.push(e.to);
      }
    }
  }

  vector<vector<int>> groups;

  for (int i = 1; i < n; i++) {
    if (dists[i].size()) groups.push_back(dists[i].begin()->second);
  }

  vector<vector<bool>> ans;

  vector<bool> c(m);

  GenAns(groups, ans, c, k, 0);

  cout << ans.size() << endl;
  for (auto it : ans) {
    for (auto a : it) {
      cout << ("01"[a]);
    }
    cout << endl;
  }

  return 0;
}
