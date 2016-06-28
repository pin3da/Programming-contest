#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int get_id(unordered_map<string, int> &g, string &a) {
  if (g.count(a))
    return g[a];
  int ans = g.size();
  return g[a] = ans;
}

const int inf = 1000000;

int bfs(vector<vector<int>> &g, int s, int tar) {
  deque<int> q;
  q.push_back(s);

  vector<int> dist(g.size(), inf);
  dist[s] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop_front();
    for (auto &to : g[cur]) {
      if (dist[to] == inf) {
        dist[to] = dist[cur] + 1;
        q.push_back(to);
      }
    }
  }
  return dist[tar];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> g(n);
    unordered_map<string, int> id;
    for (int i = 0; i < m; ++i) {
      string a, b;
      cin >> a >> b;
      int u = get_id(id, a), v = get_id(id, b);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }

    string ss = "Entrada";
    string tar = "*";
    int begin = bfs(g, get_id(id, ss), get_id(id, tar));
    ss = "Saida";
    int end = bfs(g, get_id(id, ss), get_id(id, tar));
    cout << begin + end << endl;
  }
  return 0;
}
