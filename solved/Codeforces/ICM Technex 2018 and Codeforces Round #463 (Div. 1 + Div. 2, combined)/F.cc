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
typedef long long int64;
typedef long double float128;

const int64 is_query = -(1LL<<62), inf = 1e18;

struct Line {
  int64 m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    int64 x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (float128)(x->b - y->b)*(z->m - y->m) >= (float128)(y->b - z->b)*(y->m - x->m);
  }
  void insert_line(int64 m, int64 b) {
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }

  int64 eval(int64 x) {
    auto l = *lower_bound((Line) { x, is_query });
    return l.m * x + l.b;
  }
};


const int MN = 100000 + 100;

long long dp[MN];
HullDynamic bag[MN];
int sz[MN];
int id[MN];
int total;

typedef vector<vector<int>> graph;

void dfs(graph &g, vector<int> &a, vector<int>&b, int node, int p) {
  int id_big = -1;

  sz[node] = 1;

  for (auto to : g[node]) if (to != p) {
    dfs(g, a, b, to, node);

    if (id_big < 0 || (sz[id_big] < sz[to]))
      id_big = to;

    sz[node] += sz[to];
  }

  if (id_big < 0) { // leaf
    dp[node] = 0;
    id[node] = total++;
    bag[id[node]].insert_line(-b[node], 0);
  } else { // merge children
    id[node] = id[id_big];

    for (auto to : g[node]) if (to != p) {
      if (to != id_big) {
        for (auto l : bag[id[to]]) {
          bag[id[node]].insert_line(l.m, l.b);
        }
      }
    }

    dp[node] = -bag[id[node]].eval(a[node]);
    bag[id[node]].insert_line(-b[node], -dp[node]);
  }
}

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  read(a, b);


  graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    read(u, v);
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }


  dfs(g, a, b, 0, 0);
  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

