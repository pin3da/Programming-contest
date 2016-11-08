#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " : " << x << endl

const int MN = 22;
long long c[MN];

struct edge {
  int to;
  long long cost;
  edge() {}
  edge(int a, long long b) : to(a), cost(b) {}
  bool operator < (const edge &o) const {
    return cost > o.cost;
  }
};


const int MVAL = 1234;
vector<edge> g[MVAL];
long long dist[MVAL];
long long inf = 1LL << 61;

int main() {
  int n; long long k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> c[i];

  int mod = *min_element(c, c + n);
  for (int i = 0; i < mod; ++i) {
    for (int j = 0; j < n; ++j) {
      int to = (i + c[j]) % mod;
      g[i].push_back(edge(to, c[j]));
    }
  }

  for (int i = 0; i < mod; ++i)
    dist[i] = inf;

  priority_queue<edge> q;
  q.push(edge(0, 0));
  dist[0] = 0;

  while (!q.empty()) {
    int node = q.top().to;
    long long cost = q.top().cost;
    q.pop();

    if (cost > dist[node]) continue;
    for (int i = 0; i < (int)g[node].size(); ++i) {
      int to = g[node][i].to;
      long long w_extra = g[node][i].cost;
      if (dist[node] + w_extra < dist[to]) {
        dist[to] = dist[node] + w_extra;
        q.push(edge(to, dist[to]));
      }
    }
  }

  long long target = k % mod;
  puts(dist[target] <= k ? "possible" : "impossible");
  return 0;
}
