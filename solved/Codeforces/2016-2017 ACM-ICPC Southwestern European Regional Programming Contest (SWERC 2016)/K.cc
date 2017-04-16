#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long BASE = 1001;

struct point{
  long long x, y, z;
  long long id = 0;
  point(long long a, long long b, long long c) :
      x(a), y(b), z(c) {

    id = (((x * BASE) + y) * BASE) + z;
  }
};

bool dfs(vector<vector<int>> &g, vector<int> &color, int node, int pi) {
  if (color[node] == 2) return false;
  if (color[node] == 1) return true;

  color[node] = 1;
  for (int to : g[node]) {
    if (to == pi) continue;
    if (dfs(g, color, to, node))
      return true;
  }
  color[node] = 2;
  return false;
}

bool has_cycle(vector<vector<int>> &g) {
  vector<int> color(g.size(), 0);
  for (int i = 0; i < (int)g.size(); ++i) {
    if (color[i] == 0) {
      if (dfs(g, color, i, i))
        return true;
    }
  }
  return false;
}

int get_id(map<long long, int> &id, long long x) {
  if (id.count(x))
    return id[x];
  int ans = id.size();
  id[x] = ans;
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int k; cin >> k;
  vector<vector<int>> g2d(2 * k + 10);
  vector<vector<int>> g3d(2 * k + 10);

  map<long long, int> id2d, id3d;

  set<pair<long long, long long>> edges3d, edges2d;

  for (int i = 0; i < k; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    point u(x, y, z);
    point a(x, y, 0);
    cin >> x >> y >> z;
    point v(x, y, z);
    point b(x, y, 0);

    edges3d.insert(make_pair(min(u.id, v.id), max(u.id, v.id)));
    edges2d.insert(make_pair(min(a.id, b.id), max(a.id, b.id)));
  }

  for (auto ed : edges3d) {
    int u = get_id(id3d, ed.first);
    int v = get_id(id3d, ed.second);
    if (u == v) continue;
    g3d[u].push_back(v);
    g3d[v].push_back(u);
  }

  for (auto ed : edges2d) {
    int u = get_id(id2d, ed.first);
    int v = get_id(id2d, ed.second);
    if (u == v) continue;
    g2d[u].push_back(v);
    g2d[v].push_back(u);
  }

  puts(has_cycle(g3d) ? "True closed chains" : "No true closed chains");
  puts(has_cycle(g2d) ? "Floor closed chains" : "No floor closed chains");
  return 0;
}
