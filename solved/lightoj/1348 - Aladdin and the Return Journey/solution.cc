using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<< (x)<<endl


const int MAXM = 16;
const int MAXN = 1 << MAXM;

struct bit{
  long long v[MAXN];
  int maxSize;

  void init(int n) {
    maxSize = n;
    memset(v, 0, sizeof v);
  }
  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }
  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }
  long long query(int from, int to){
    return query(to) - query(from-1);
  }

};


bit ft;
int n;
int val[MAXN];

// Heavy-Light Decomposition
struct TreeDecomposition {
  vector<int> g[MAXN], c[MAXN];
  int s[MAXN]; // subtree size
  int p[MAXN]; // parent id
  int r[MAXN]; // chain root id
  int t[MAXN]; // index used in segtree/bit/...
  int d[MAXN]; // depht
  int ts;

  void dfs(int v, int f) {
    p[v] = f;
    s[v] = 1;
    if (f != -1) d[v] = d[f] + 1;
    else d[v] = 0;

    for (int i = 0; i < g[v].size(); ++i) {
      int w = g[v][i];
      if (w != f) {
        dfs(w, v);
        s[v] += s[w];
      }
    }
  }

  void hld(int v, int f, int k) {
    ft.add(ts, val[v]);
    t[v] = ts++;
    c[k].push_back(v);
    r[v] = k;

    int x = 0, y = -1;
    for (int i = 0; i < g[v].size(); ++i) {
      int w = g[v][i];
      if (w != f) {
        if (s[w] > x) {
          x = s[w];
          y = w;
        }
      }
    }
    if (y != -1) {
      hld(y, v, k);
    }

    for (int i = 0; i < g[v].size(); ++i) {
      int w = g[v][i];
      if (w != f && w != y) {
        hld(w, v, w);
      }
    }
  }

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      g[i].clear();
    }
  }

  void add(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }

  void build() {
    ts = 0;
    dfs(0, -1);
    hld(0, 0, 0);
  }
};

TreeDecomposition tree;



int magic(int a, int b) {  // C : LCA btwn a and b
  if ( tree.r[a] == tree.r[b] ) {
    int ia = tree.t[a];
    int ib = tree.t[b];
    if (ia > ib) swap(ia,ib);
    return ft.query(ia, ib);
  }

  int ans = 0;

  if (tree.d[tree.r[a]] > tree.d[tree.r[b]]) {
    ans += ft.query(tree.t[tree.r[a]], tree.t[a]) +  magic(tree.p[tree.r[a]], b);
  } else {
    ans += ft.query(tree.t[tree.r[b]], tree.t[b]) +  magic(tree.p[tree.r[b]], a);
  }

  return ans;
}

void solve() {
  scanf("%d", &n);
  tree.init(n+1);
  ft.init(n+1);
  for (int i = 0; i < n; ++i) scanf("%d", val + i);

  int u, v;
  for (int i = 0; i < (n - 1); ++i ) {
    scanf("%d%d", &u,&v);
    tree.add(u,v);
  }

  tree.build();


  int queries; scanf("%d", &queries);
  int type, a, b;
  while (queries-- ) {
    scanf("%d%d%d", &type, &a, &b);
    if (type) {
      int idx = tree.t[a];
      ft.add(idx, -ft.query(idx,idx));
      ft.add(idx, b);
    } else {
      printf("%lld\n",magic(a , b));
    }
  }

}

int main() {

  int tc; scanf("%d", &tc);
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i+1);
    solve();
  }
  return 0;
}
