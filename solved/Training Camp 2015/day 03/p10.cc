using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 333;
long long g[MN][MN];
const int inf = 1 << 30;

void debug(map<pair<int, int>, int>::iterator it, map<pair<int, int>, int>::iterator it2) {
  cout << "a " << it->first.first << " " << it->first.second << endl;
  cout << "b " << it2->first.first << " " << it2->first.second << endl;
  cout << "cost : " << g[it->second][it2->second] << endl;
}

void solve() {
  int n, f, m;
  cin >> n >> f >> m;
  memset(g, 0, sizeof g);

  map<pair<int, int>, int> cod;

  int nodes = 0;
  for (int i = 0; i < n; ++i)
    cod[make_pair(i, 0)] = nodes++;

  for (int i = 0; i < n; ++i) {
    g[cod[make_pair(i, 0)]][cod[make_pair((i + 1) % n, 0)]] = 1;
    g[cod[make_pair((i + 1) % n, 0)]][cod[make_pair(i, 0)]] = 1;
  }


  int a, b, c, d, cost;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c >> d >> cost;
    a--;b--;c--;d--;
    int u, v;
    if (cod.count(make_pair(a, b)) == 0)
      cod[make_pair(a, b)] = nodes++;

    if (cod.count(make_pair(c, d)) == 0)
      cod[make_pair(c, d)] = nodes++;

    u = cod[make_pair(a, b)];
    v = cod[make_pair(c, d)];
    g[u][v] += cost;
    g[v][u] += cost;

    auto it = cod.upper_bound(make_pair(a, b));
    if (it != cod.end() && it->second != u && it->first.first == a) {
      g[u][it->second] += llabs(b - it->first.second);
      g[it->second][u] += llabs(b - it->first.second);
    }
    it = cod.lower_bound(make_pair(a, b));
    if (it != cod.begin()) {
      it--;
      if ( it->first.first == a) {
        g[u][it->second] += llabs(b - it->first.second);
        g[it->second][u] += llabs(b - it->first.second);
      }
    }

    it = cod.upper_bound(make_pair(c, d));
    if (it != cod.end() && it->second != v && it->first.first == c) {
      g[v][it->second] += llabs(d - it->first.second);
      g[it->second][v] += llabs(d - it->first.second);
    }

    it = cod.lower_bound(make_pair(c, d));
    if (it != cod.begin()) {
      it--;
      if (it->first.first == c) {
        g[v][it->second] += llabs(d - it->first.second);
        g[it->second][v] += llabs(d - it->first.second);
      }
    }
  }


  for (int i = 0; i < nodes; ++i) {
    for (int j = 0; j < nodes; ++j) {
      if (g[i][j] == 0)
        g[i][j] = inf;
      if (i == j)
        g[i][j] = 0;
    }
  }

  for (int k = 0; k < nodes; ++k) {
    for (int i = 0; i < nodes; ++i) {
      for (int j = 0; j < nodes; ++j) {
        g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
      }
    }
  }


  int q;
  cin >> q;
  while (q--) {
    cin >> a >> b >> c >> d;
    a--; b--;c--; d--;
    auto it = cod.lower_bound(make_pair(a, b));
    auto it2 = cod.lower_bound(make_pair(c, d));

    if (it->first.first != a) it--;
    assert(it->first.first == a);
    if (it2->first.first != c) it2--;
    assert(it2->first.first == c);


    long long best = llabs(it->first.second - b) + g[it->second][it2->second] + llabs(it2->first.second - d);
    if (a == c)
      best = llabs(d - b);

    if (it2 != cod.begin()) {
      it2--;
      if (it2->first.first == c) {
        best = min(best, llabs(it->first.second - b) + g[it->second][it2->second] + llabs(it2->first.second - d));
        if (it != cod.begin()) {
          it--;
          if (it->first.first == a) {
            best = min(best, llabs(it->first.second - b) + g[it->second][it2->second] + llabs(it2->first.second - d));
          }
          it++;
        }
      }
      it2++;
    }
    if (it != cod.begin()) {
      it--;
      if (it->first.first == a) {
        best = min(best, llabs(it->first.second - b) + g[it->second][it2->second] + llabs(it2->first.second - d));
      }
    }

    cout << best << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc --) {
    solve();
  }
  return 0;
}
