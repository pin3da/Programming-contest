using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct edge{
  int u, v, w;
  edge() {}
  edge(int a, int b, int c) : u(a), v(b), w(c) {}
  bool operator < ( const edge &o ) const {
    return w < o.w;
  }
};

int p[1111];

int fs(int x) {
  return x == p[x] ? x : (p[x] = fs(p[x]));
}

void j(int a, int b) {
  p[fs(a)] = fs(b);
}

void solve() {
  int n;
  cin >> n;
  map<string, int> cod;
  string a, b;
  int cost;
  vector<edge> edges;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> cost;
    if (!cod.count(a))
      cod[a] = cod.size() - 1;

    if (!cod.count(b))
      cod[b] = cod.size() - 1;

    edges.push_back(edge(cod[a], cod[b], cost));
  }

  for (int i = 0; i < cod.size(); ++i) {
    p[i] = i;
  }

  sort(edges.begin(), edges.end());
  int ans = 0;
  for (int i = 0; i < edges.size(); ++i) {
    edge &e = edges[i];
    if (fs(e.u) != fs(e.v)) {
      ans += e.w;
      j(e.u, e.v);
    }
  }

  set<int> seen;
  for (int i = 0; i < cod.size(); ++i) {
    if (!seen.count(fs(i)))
      seen.insert(fs(i));
  }

  if (seen.size() == 1) {
    printf("%d\n", ans);
  } else {
    puts("Impossible");
  }

}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
