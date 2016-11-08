#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl
#define forall(it, x) for (typeof x.begin() it = x.begin(); it != x.end(); ++it)

const int MN = 50005;

struct edge {
  int u, v, t;
  long long w;
  edge() {}
  edge(int a, int b, long long c, int d) : u(a), v(b), w(c), t(d) {}
  bool operator < (const edge &o) const {
    if (w == o.w) {
      return t > o.t;
    }
    return w < o.w;
  }
};

int p[MN];

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  if (fs(x) == fs(y)) return 1;
  p[fs(x)] = fs(y);
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, m, l;
  cin >> n >> m >> l;
  for (int i = 0; i < n; ++i) p[i] = i;
 
  vector<edge> all;
  long long disp = 0; 
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;v--;
    all.push_back(edge(u, v, c, i < l));
    if (i < l) disp += c;
  }
  sort(all.begin(), all.end());
  
  for (int i = 0; i < all.size(); ++i) {
    int u = all[i].u, v = all[i].v, t = all[i].t;
    long long w = all[i].w;
    if (!js(u, v)) {
      disp -= w;
    }
  }
  
  int ok = 1;
  set<int> fff;
  for (int i = 0; i < n; ++i)
    fff.insert(fs(i));
  
  if (disp >= 0 && (fff.size() == 1)) {
    cout << "possible" << endl;
  } else {
    cout << "impossible" << endl;
  }
  return 0;
}
