#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef unordered_map<int, int> umap;

const int MN = (100000 + 100) << 1;

int p[MN];
int c[MN];

int get_id(umap &s, int id) {
  if (s.count(id))
    return s[id];
  int ans = s.size();
  return s[id] = ans;
}

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

void js(int x, int y) {
  if (fs(x) == fs(y)) {
    c[fs(x)]++;
  } else {
    c[fs(y)] += c[fs(x)];
    p[fs(x)] = fs(y);
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m && (n + m)) {
    unordered_map<int, int> seen(m << 1);
    set<pair<int, int>> q;

    for (int i = 0; i < MN; ++i) p[i] = i, c[i] = 0;

    vector<set<int>> g(m << 1);
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      u = get_id(seen, u);
      v = get_id(seen, v);
      g[u].insert(v);
      g[v].insert(u);
      if (u > v) swap(u, v);
      if (q.count(make_pair(u, v))) continue;
      q.insert(make_pair(u, v));
      js(u, v);
    }

    int ok = true;
    for (auto &i : g) {
      if (i.size() > 2) ok = false;
    }
    if (!ok) {
      cout << "N" << endl;
      continue;
    }

    set<int> comp;
    for (int i = 0; i < seen.size(); ++i)
      comp.insert(fs(i));

    int cycles = 0;
    for (auto &i: comp) {
      cycles += c[i];
    }

    if (cycles == 0 ||
        (cycles == 1 && seen.size() == n && comp.size() == 1)) {
      cout << "Y" << endl;
      continue;
    }
    cout << "N" << endl;

  }
  return 0;
}
