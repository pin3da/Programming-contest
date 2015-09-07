using namespace std;
#include <bits/stdc++.h>
#define foreach(it, v) for(typeof v.begin() it = v.begin(); it != v.end(); ++it)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) :
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
    found(N), dist(N), pi(N), width(N), dad(N) {}

  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }

  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;

    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};

void solve() {
  int n, k, g, t;
  cin >> n >> k >> g;
  int N = 2 * n;
  MinCostMaxFlow pos(N + 2), neg (N + 2);
  int source = N, sink = N + 1;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos.AddEdge(source, i, 1, 0);
    neg.AddEdge(source, i, 1, 0);
    pos.AddEdge(i + n, sink, 1, 0);
    neg.AddEdge(i + n, sink, 1, 0);
  }

  for (int i = 0; i < n; ++i) {
    cin >> t;
    for (int j = 0; j < n; ++j) {
      if (a[j] < t) {
        int q = t - a[j] - k;
        pos.AddEdge(j, i + n, 1, min(g, q * q));
        neg.AddEdge(j, i + n, 1, g - min(g, q * q));
      }
    }
  }

  pair<int, int> ans = pos.GetMaxFlow(source, sink);
  if (ans.first != n) {
    puts("impossible");
  } else {
    printf("%d %d\n", ans.second, g * n - neg.GetMaxFlow(source, sink).second);
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
