using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

struct edge{
  int to, weight;
  edge() {}
  edge(int t, int w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};

const int MN = 50005;
vector<edge> g[MN];
int d[MN];
int p[MN];
int dijkstra(int s, int n){
  for (int i = 0; i < n + 10; ++i) {
    d[i] = INT_MAX;
    p[i] = -1;
  }
  d[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()) {
    int node = q.top().to;
    int dist = q.top().weight;
    q.pop();

    if (dist > d[node]) continue;

    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i].to;
      int w_extra = g[node][i].weight;

      if (dist + w_extra < d[to]) {
        d[to] = dist + w_extra;
        p[to] = node;
        q.push(edge(to, d[to]));
      }
    }
  }
  return INT_MAX;
}

struct entry {
  int u, v, w, ok;
  entry(int a, int b, int c) : u(a), v(b), w(c), ok(1) {}
};

int best = 0;

void dfs(vector<vector<edge> > &f, vector<bool> &vi, int node, int dist) {
  if (vi[node])
    return;
  vi[node] = true;
  best = max(best, dist);

  for (int i = 0; i < f[node].size(); ++i) {
    if (!vi[f[node][i].to])
      dfs(f, vi, f[node][i].to, dist + f[node][i].weight);
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, s, a, b, m;
  while (cin >> n >> s >> a >> b >> m) {
    if (n == -1 && s == - 1 && a == -1 && b == - 1 && m == - 1)
      break;
    s--;a--;b--;
    int u, v, w;
    vector<entry> all;
    for (int i = 0; i < MN; ++i) {
      g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      cin >> u >> v >> w;
      u--, v--;
      g[u].push_back(edge(v, w));
      g[v].push_back(edge(u, w));

      all.push_back(entry(u, v, w));
      all.push_back(entry(v, u, w));
    }

    dijkstra(s, n);
    vector<int> ds(n);
    for (int i = 0; i < n; ++i) {
      ds[i] = d[i];
    }

    dijkstra(a, n);
    vector<int> da(n);
    for (int i = 0; i < n; ++i) {
      da[i] = d[i];
    }


    dijkstra(b, n);
    vector<int> db(n);
    for (int i = 0; i < n; ++i) {
      db[i] = d[i];
    }

    vector<vector<edge> >  f(n);
    for (int i = 0; i < all.size(); ++i) {
      int u, v, w;
      u = all[i].u; v = all[i].v; w = all[i].w;

      all[i].ok = true;
      if ((ds[u] + w + da[v]) != ds[a])
        all[i].ok = false;
      if ((ds[u] + w + db[v]) != ds[b])
        all[i].ok = false;

      if (all[i].ok) {
        f[u].push_back(edge(v, w));
      }
    }

    best = 0;

    vector<bool> vi(n, false);
    dfs(f, vi, s, 0);

    cout << best << " " << max(0, ds[a] - best) << " " << max(0, ds[b] - best) << endl;
  }
  return 0;
}

