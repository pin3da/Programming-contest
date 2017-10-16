#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int get_id(map<string, int> &id, string &name) {
  if (id.count(name)) return id[name];
  int s = id.size();
  id[name] = s;
  return s;
}

pair<int, int> go(vector<vector<int>> &g, vector<double> &vel, int node, int can) {

  pair<int, int> all;
  for (auto to: g[node]) {
    all = sum(all, go(g, vel, to, 1));
  }

  if (!can) {
    return all;
  }
  for (auto to: g[node]) {
    auto next = sub(all, go(g, vel, to, 1));
    next = add(next, go(g, vel, to, 0));
    next.second += 1;
    next.first += min(vel[node], vel[to]);
  }
  return next;
}

void solve() {
  int n;
  cin >> n;
  map<string, int> id;
  vector<double> vel(n);
  int root = 0;
  vector<vector<int>> g(n);
  int sink = n + 1;
  int source = sink + 1;

  for (int i = 0; i < n; i++) {
    string name; cin >> name;
    double speed; cin >> speed;
    string parent; cin >> parent;
    int u = get_id(id, name);
    vel[u] = speed;
    if (parent != "CEO") {
      int v = get_id(id, parent);
      g[u].push_back(v);
      g[v].push_back(u);
    } else {
      root = u;
    }
  }

  cout << go(g, vel, root) << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  solve();
  return 0;
}
