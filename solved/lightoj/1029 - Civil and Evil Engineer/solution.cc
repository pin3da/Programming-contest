using namespace std;
#include <bits/stdc++.h>

struct edge{
  int u, v, w;
  edge() {}
  edge(int a, int b, int c) : u(a), v(b), w(c) {}
  bool operator < (const edge &o) const {
    return w < o.w;
  }
};

int p[111];
int fs(int x) {
  return (p[x] == x) ? x : (p[x] = fs(p[x]));
}

void j(int x, int y) {
  p[fs(x)] = fs(y);
}

bool f(int x, int y) {
  return fs(x) == fs(y);
}


long long mst(const vector<edge> &e, int n) {
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }

  long long ans = 0;
  for (int i = 0; i < e.size(); ++i) {
    const edge &cur = e[i];
    if (!f(cur.u, cur.v)) {
      j(cur.u, cur.v);
      ans += cur.w;
    }
  }

  return ans;
}

void solve() {
  int n;
  cin >> n;
  int u, v, w;
  vector<edge> edges;
  while (cin >> u >> v >> w && (u + v + w)) {
    edges.push_back(edge(u, v, w));
  }
  sort(edges.begin(), edges.end());
  long long ans = mst(edges, n + 1);
  reverse(edges.begin(), edges.end());
  ans += mst(edges, n + 1);
  if (ans & 1)
    cout << ans << "/2" << endl;
  else
    cout << (ans >> 1) << endl;

}


int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case " << i + 1 << ": ";
    solve();
  }
  return 0;
}
