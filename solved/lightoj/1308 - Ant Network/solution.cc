using namespace std;
#include<bits/stdc++.h>

#define forall(it, x) for(typeof x.begin() it = x.begin(); \
    it != x.end(); ++it)

#define debug(x) cout << #x " = " << (x) << endl

struct edge {
  int to, id;
  edge(int a, int b) : to(a), id(b) {}
};

const int MN = 12345;
const int MM = 23456;

struct art_points {
  vector<edge> g[MN];
  vector<edge> edges;
  int low[MN], d[MN], color[MN];
  set<int> cameras;
  int timestamp;
  int n;
  art_points() {}

  void init(int _n, int m) {
    n = _n;
    for (int i = 0; i < n; ++i)
      g[i].clear();
    edges.clear();
  }

  void add_edge(int u, int v) {
    g[u].push_back(edge(v, edges.size()));
    g[v].push_back(edge(u, edges.size()));
    edges.push_back(edge(u, v));
  }

  void dfs(int v, bool root = true){
    color[v] = 1;
    d[v] = low[v] = ++timestamp;
    int count = 0;
    for (int i = 0; i < (int)g[v].size(); ++i) {
      int to = g[v][i].to;
      if (color[to] == 0) {
        //(v, neighbors[i]) is a tree edge
        dfs(to, false);
        if (!root && low[to] >= d[v]) {
          //current node is an articulation point
          cameras.insert(v);
        }
        low[v] = min(low[v], low[to]);
        ++count;
      }else{ // (v, neighbors[i]) is a back edge
        low[v] = min(low[v], d[to]);
      }
    }
    if (root && count > 1){
      // is root and has two neighbors in the DFS-tree
      cameras.insert(v);
    }
    color[v] = 2;
  }
  void comp_ap() {
    memset(color, 0, sizeof color);
    memset(d, 0, sizeof d);
    memset(low, 0, sizeof low);
    timestamp = 0;
    cameras.clear();
    for (int i = 0; i < n; ++i)
      if (!color[i]) dfs(i);
  }
};

struct dsu {
  int p[MN];
  void init(int n) {
    for (int i = 0; i < n; ++i)
      p[i] = i;
  }
  int fs(int x) {
    return x == p[x] ? x : p[x] = fs(p[x]);
  }
  void js(int x, int y) {
    p[fs(x)] = fs(y);
  }
};

art_points g;
dsu ds;
set<int> frec[MN], comp[MN];
int len[MN];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  g.init(n, m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g.add_edge(u, v);
  }
  g.comp_ap();

  ds.init(n);

  forall(e, g.edges) {
    int u = e-> to, v = e-> id;
    if (g.cameras.count(u) || g.cameras.count(v))
      continue;
    ds.js(u, v);
  }

  memset(len, 0, sizeof len);
  for (int i = 0; i < n; ++i) {
    frec[i].clear();
    comp[i].clear();
    len[ds.fs(i)]++;
  }


  set<int> biconect;
  forall(e, g.edges) {
    int u = e-> to, v = e-> id;
    if (g.cameras.count(u) && g.cameras.count(v)) continue;
    if (ds.fs(u) == ds.fs(v)) continue;
    if (g.cameras.count(u) == 0)
      swap(u, v);

    biconect.insert(ds.fs(v));
    frec[ds.fs(v)].insert(u);
    // comp[u].insert(ds.fs(v));
  }



  int ans = 0;
  unsigned long long ways = 1;
  forall(co, biconect) {
    if (frec[*co].size() == 1) {
      ans++;
      ways *= len[*co];
    }
  }

  if (ans == 0)
    printf ("%d %d\n", 2, n * (n - 1) / 2);
  else
    printf("%d %llu\n", ans, ways);
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tid = 1; tid <= tc; ++tid) {
    printf("Case %d: ", tid);
    solve();
  }
  return 0;
}

