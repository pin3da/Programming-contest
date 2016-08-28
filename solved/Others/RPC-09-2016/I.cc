#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long double T;

struct pt {
  T x, y, r;
  bool operator < (const pt & o) const {
    if (y == o.y) return x < o.x;
    return y < o.y;
  }
};

struct edge {
  int to;
  T cost;
  edge() {}
  edge(int a, T b) : to(a), cost(b) {}
  bool operator <(const edge &o) const {
    return cost > o.cost;
  }
};

T dist_r(const pt &a, const pt &b) {
  T x = a.x - b.x;
  T y = a.y - b.y;
  T d = sqrt(x* x + y * y);
  T ans = d - a.r - b.r;
  return max<T>(ans, 0);
}


T dijkstra(vector<vector<edge> > &g, int s, int tar) {
  vector<T> dist(g.size(), 1e100);

  dist[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()) {
    edge cur = q.top(); q.pop();
    int node = cur.to;
    if (cur.cost > dist[node]) continue;
    for (int i = 0; i < g[node].size(); ++i) {
      int to = g[node][i].to;
      T extra = g[node][i].cost;
      if (cur.cost + extra < dist[to]) {
        dist[to] = cur.cost + extra;
        q.push(edge(to, dist[to]));
      }
    }
  }
  return dist[tar];
}

void solve() {
  int n; cin >> n;
  vector<pt> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].r;
  }
  cin >> n;
  pt t;
  vector<int> from, to;
  for (int i = 0; i < n; ++i) {
    cin >> t.x >> t.y; t.r = 0;
    from.push_back(a.size());
    a.push_back(t);
    cin >> t.x >> t.y; t.r = 0;
    to.push_back(a.size());
    a.push_back(t);
  }

  vector<vector<edge> > g(a.size());

  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < a.size(); ++j) {
      g[i].push_back(edge(j, dist_r(a[i], a[j])));
    }
  }


  for (int i = 0; i < from.size(); ++i) {
    T ans = dijkstra(g, from[i], to[i]);
    cout << "Path #" << (i + 1) << ": Shortest sun distance is " << ans << "." << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  int tid = 1;
  cout << fixed << setprecision(1);
  while (tc--) {
    cout << "Campus #" << (tid++) << ":" << endl;
    solve();
  }
  return 0;
}
