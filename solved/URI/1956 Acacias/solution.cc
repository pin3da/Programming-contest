#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 10001;
int p[MN];

struct edge {
  int from, to, w;
  edge() {}
  edge(int c, int a, int b) : from(c), to(a), w(b) {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

int fs(int x) {
  return (p[x] == x ? x : p[x] = fs(p[x])) ;
}

bool js(int x, int y) {
  if (fs(x) == fs(y)) return false;
  p[fs(x)] = fs(y); return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<edge> g;
    for (int i = 0; i < n; ++i)
      p[i] = i;

    for (int i = 0; i < n - 1; ++i) {
      int k;cin >> k;
      for (int j = 0; j < k; ++j) {
        int v, w; cin >> v >> w;
        v--;
        g.emplace_back(i, v, w);
      }
    }
    sort(g.begin(), g.end());
    long long total = 0;
    for (int i = 0; i < g.size(); ++i) {
      int u = g[i].from, v = g[i].to, w = g[i].w;
      if (js(u, v)) total += w;
    }
    set<int> seen;
    for (int i = 0; i < n; ++i) seen.insert(fs(i));
    cout << seen.size() << ' ' << total << endl;
  }

  return 0;
}
