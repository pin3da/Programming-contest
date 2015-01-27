using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = "  << (x) << endl

const int inf = 1000000 + 10;

struct entry{
  int u, v, b, c;
};

struct edge {
  int u, v, w;
  edge() {}
  edge(int a,int b,int c) : u(a), v(b), w(c) {}
  bool operator < (const edge& o) const {
    if (u == o.u)
      if (v == o.v)
        return w < o.w;
      else
        return v < o.v;
    return u < o.u;
  }
};

int dmst(vector<edge> &edges, int root, int n) {
  int ans = 0;
  int cur_nodes = n;
  while (true) {
    vector<int> lo(cur_nodes, inf), pi(cur_nodes, inf);
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      if (w < lo[v] and u != v) {
        lo[v] = w;
        pi[v] = u;
      }
    }

    lo[root] = 0;
    for (int i = 0; i < lo.size(); ++i) {
      if (i == root) continue;
      if (lo[i] == inf) return -1;
    }
    int cur_id = 0;
    vector<int> id(cur_nodes, -1), mark(cur_nodes, -1);
    for (int i = 0; i < cur_nodes; ++i) {
      ans += lo[i];
      int u = i;
      while (u != root and id[u] < 0 and mark[u] != i) {
        mark[u] = i;
        u = pi[u];
      }
      if (u != root and id[u] < 0) { // Cycle
         for (int v = pi[u]; v != u; v = pi[v])
           id[v] = cur_id;
         id[u] = cur_id++;
      }
    }

    if (cur_id == 0)
      break;

    for (int i = 0; i < cur_nodes; ++i)
      if (id[i] < 0) id[i] = cur_id++;

    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      edges[i].u = id[u];
      edges[i].v = id[v];
      if (id[u] != id[v])
        edges[i].w -= lo[v];
    }
    cur_nodes = cur_id;
    root = id[root];
  }

  return ans;
}

bool fun(vector<entry> &entries, int n, int c, int mid) {
  vector<edge> edges;
  for (int i = 0; i < entries.size(); ++i) {
    if (entries[i].b >= mid) {
      int u = entries[i].u, v = entries[i].v, w = entries[i].c;
      edges.push_back(edge(u, v, w));
    }
  }

  int cost = dmst(edges, 0, n);
  if (cost > -1 and cost <= c)
    return true;
  return false;
}

void solve() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<entry> entries(m);
  for (int i = 0; i < m; ++i) {
    cin >> entries[i].u  >>  entries[i].v >>  entries[i].b >>  entries[i].c;
  }

  int seen = false;
  int lo = 0, hi = inf;
  while (lo < hi) {
    if (lo + 1 == hi) {
      if (fun(entries, n, c, hi)) {
        seen = true;
        lo = hi;
      }
      break;
    }
    int mid = (lo + hi) / 2;
    if (fun(entries, n, c, mid)) {
      lo = mid;
      seen = true;
    } else
      hi = mid - 1;
  }
  if (seen)
    printf("%d kbps\n", lo);
  else
    printf("impossible\n");
}

int main() {
  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
