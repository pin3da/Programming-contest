// Chef and Average on a Tree
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MN = 100000 + 100;

struct dsu {
  int p[MN], sz[MN];
  long long sum[MN];

  void init(vector<int> &w) {
    for (int i = 0; i < int(w.size()); i++) {
      p[i] = i;
      sum[i] = w[i];
      sz[i] = 1;
    }
  }

  int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  }

  int join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return 0;
    sz[py] += sz[px];
    sum[py] += sum[px];
    p[px] = py;
    cerr << "join " << x << " " << y << " into " << py << endl;
    return 1;
  }
};

dsu dset;

double get_avg(int x, int y) {
  double sum = dset.sum[x] + dset.sum[y];
  double len = dset.sz[x] + dset.sz[y];
  return sum / len;
}

double get_avg(int x) {
  return double(dset.sum[x]) / dset.sz[x];
}

int find_next(vector<vector<int>> &g, vector<int> &w, vector<int> &used,
    int id, double tar) {
  int n = g.size();
  int ans = -1, best = 1e6;
  set<int> seen;
  pair<int, int> edge;
  for (int i = 0; i < n; i++) {
    if (dset.find(i) == id && used[i] < 2) {
      for (auto to : g[i]) {
        int dt = dset.find(to);
        if (dt != id && seen.count(dt) == 0) {
          if (get_avg(dset.find(id), dt) < tar) continue;
          if (w[to] < best) {
            best = w[to];
            ans = dt;
            seen.insert(dt);
            edge = {i, to};
          }
        }
      }
    }
  }

  if (ans == - 1) {
    for (int i = 0; i < n; i++) {
      if (dset.find(i) == id && used[i] < 2) {
        for (auto to : g[i]) {
          int dt = dset.find(to);
          if (dt != id && seen.count(dt) == 0) {
            //  if (get_avg(dset.find(id), dt) < tar) continue;
            if (w[to] < best) {
              best = w[to];
              ans = dt;
              seen.insert(dt);
              edge = {i, to};
            }
          }
        }
      }
    }
  }

  if (ans != -1) {
    used[edge.first]++;
    used[edge.second]++;
  }

  return ans;
}



void solve() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  vector<int> used(n);
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  set<pair<double, int>> groups;
  dset.init(w);

  for (int i = 0; i < n; i++)
    groups.insert({double(w[i]), i});

  while (groups.size() > 1) {
    // cerr << "-----" << endl;
    auto cur = *(groups.begin());
    groups.erase(groups.begin());

    double second = 0;
    if (groups.size() > 1) {
      auto tmp = groups.begin();
      tmp++;
      second = tmp->first;
    }

    // debug(cur.second);
    // debug(cur.first);
    int nxt = find_next(g, w, used, cur.second, second);
    if (nxt < 0) continue;
    // debug(nxt);

    double avg = cur.first;
    double op = get_avg(cur.second, nxt);

    // debug(op);

    if (avg > op) continue;

    groups.erase({get_avg(nxt), nxt});
    groups.erase({get_avg(cur.second), cur.second});

    dset.join(cur.second, nxt);
    groups.insert({get_avg(dset.find(nxt)), dset.find(nxt)});
  }

  double ans = 1e6;
  for (int i = 0; i < n; i++) {
    ans = min(ans, get_avg(dset.find(i)));
  }
  cout << fixed << setprecision(10) << ans << endl;
  // cerr << "=======" << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int tc;
  cin >> tc;
  while (tc--)
    solve();

  return 0;
}
