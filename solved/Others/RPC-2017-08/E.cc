#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct edge{
  int to;
  long long weight;
  edge() {}
  edge(int t, long long w) : to(t), weight(w) {}
  bool operator < (const edge &that) const {
    return weight > that.weight;
  }
};

const long long inf = 10000000LL * 10000000LL;

const int MN = 100011;
vector<edge> g[MN];
long long d[MN];
long long dijkstra(int s, int n, int tar, long long max_edge){
  for (int i = 0; i < n; ++i){
    d[i] = inf;
  }
  d[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()) {
    int node = q.top().to;
    long long dist = q.top().weight;
    q.pop();

    if (dist > d[node]) continue;

    for (int i = 0; i < (int)g[node].size(); i++){
      int to = g[node][i].to;
      long long w_extra = g[node][i].weight;
      if (w_extra > max_edge) continue;

      if (dist + w_extra < d[to]){
        d[to] = dist + w_extra;
        q.push(edge(to, d[to]));
      }
    }
  }
  return d[tar];
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m; cin >> n >> m;
  int x; cin >> x;

  long long max_w = 0;
  for (int i = 0; i < m; i++) {
    long long a, b, w;
    cin >> a >> b >> w;
    a--; b--;
    g[a].push_back(edge(b, w));
    g[b].push_back(edge(a, w));
    max_w = max(max_w, w);
  }

  long long best = dijkstra(0, n, n - 1, max_w);
  long long max_ans = (best * 100 + x * (best)) / 100;

  long long lo = 0, hi = max_w;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    long long f = dijkstra(0, n, n - 1, mid);
    if (f <= max_ans)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << endl;
  return 0;
}
