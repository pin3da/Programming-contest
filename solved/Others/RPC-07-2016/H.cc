#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MAXNODES = 50000 * 2;

struct edge{
  int to;
  long long w;
  edge(){} edge(int v, long long w) : to(v), w(w) {}
};

vector<edge> g[MAXNODES];
long long d[MAXNODES];
long long dn[MAXNODES];
int in_cycle[MAXNODES];
int vi[MAXNODES];

const long long inf = 100000000000LL;

void bellman(int s, int n) {
  for (int i = 0; i < n; ++i) {
    d[i] = dn[i] = inf;
    in_cycle[i] = false;
  }
  dn[s] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      d[j] = dn[j];
    for (int u = 0; u < n; ++u) {
      if (d[u] == inf) continue;
      for (auto &e : g[u]) {
        dn[e.to] = min(dn[e.to], d[u] + e.w);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (dn[i] < d[i])
      in_cycle[i] = true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int edges, nodes, start, end;
  while (cin >> edges >> nodes >> start >> end &&
      (edges + nodes + start + end)) {
    for (int i = 0; i < nodes + 10; ++i) {
      g[i].clear();
    }

    start--;end--;

    int u, v, w;
    double tmp;
    for (int i = 0; i < edges; ++i) {
      cin >> u >> v >> tmp;
      w = round(tmp * 1000);
      u--;v--;
      g[u].emplace_back(v, -w);
    }

    bellman(start, nodes);

    deque<int> q;
    for (int i = 0; i < nodes; ++i) {
      if (in_cycle[i]) q.push_back(i);
    }
    memset(vi, 0, sizeof vi);
    while (!q.empty()) {
      int cur = q.front();q.pop_front();
      vi[cur] = true;
      for (auto &e:  g[cur]) {
        if (!vi[e.to]) {
          q.push_back(e.to);
          vi[e.to] = true;
        }
      }
    }
    if (vi[end]) {
      cout << "TRUE" << endl;
    } else {
      cout << "FALSE" << endl;
    }
  }
  return 0;
}
