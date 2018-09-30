#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

struct Dsu {
  vector<int> p;

  Dsu(int n) {
    p.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

  int Join(int x, int y) {
    debug("join", x, y);
    int px = Find(x), py = Find(y);
    if (px == py) return 0;
    p[px] = py;
    return 1;
  }
};


struct edge {
  int u, v, w;
  edge() {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<edge> edges(m);
  for (auto &e : edges) cin >> e.u >> e.v >> e.w;
  sort(edges.begin(), edges.end());

  Dsu dsu(n + 10);

  set<int> used;
  int extra = false;
  int r1 = -1, r2 = -1;
  for (auto e : edges) {
    debug(extra, r1, r2);
    if (e.w == 0) {
      extra = true;
      used.insert(e.u);
      used.insert(e.v);
      r1 = e.u;
      r2 = e.v;
    } else {
      if (!extra) {
        if (used.count(e.u) == 0 || used.count(e.v) == 0) {
          dsu.Join(e.u, e.v);
          used.insert(e.u);
          used.insert(e.v);
        }
      } else if ((e.u != r1) && (e.v != r1) && (e.u != r2) && (e.v != r2)) {
        if (used.count(e.u) == 0 || used.count(e.v) == 0) {
          dsu.Join(e.u, e.v);
          used.insert(e.u);
          used.insert(e.v);
        }
      } else { // extra and connected to root
        used.insert(e.u);
        used.insert(e.v);
      }
    }
  }

  if (!extra) {
    set<int> roots;
    for (int i = 1; i <= n; i++) roots.insert(dsu.Find(i));
    long long ans = 1;
    int x = roots.size();
    while (x--) {
      ans *= 2;
    }
    cout << ans << endl;
  } else {
    set<int> roots;
    debug(r1, r2);
    for (int i = 1; i <= n; i++) if (i != r1 && i != r2) roots.insert(dsu.Find(i));
    long long ans = 2;
    int x = roots.size();
    debug(roots.size());
    while (x--) {
      ans *= 2;
    }
    cout << ans << endl;

  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

