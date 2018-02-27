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

struct edge {
  int to;
  long long w;
  edge () {}
  edge (int a, long long b) : to(a), w(b) {}
  bool operator < (const edge &o) const {
    return w > o.w;
  }
};

typedef vector<vector<edge>> graph;

const long long inf = 1LL << 50;

pair<vector<int>, vector<long long>> dijkstra(graph &g, int start) {
  int n = g.size();
  vector<long long> d(n, inf);
  vector<int> p(n, -1);
  d[start] = 0;
  priority_queue<edge> q;
  q.push(edge(start, 0));

  while (!q.empty()) {
    int node = q.top().to;
    long long dist = q.top().w;
    q.pop();

    if (dist > d[node]) continue;

    for (int i = 0; i < (int)g[node].size(); i++) {
      int to = g[node][i].to;
      long long w_extra = g[node][i].w;

      if (dist + w_extra < d[to]) {
        p[to] = node;
        d[to] = dist + w_extra;
        q.push(edge(to, d[to]));
      }
    }
  }

  return {p, d};
}

const int MN = 5000 + 100;
long long dp[2][MN];
long long dist[MN];
int cur;


long long cost(int b, int e) {
  long long ans = dist[e];
  if (b) return (ans - dist[b - 1]) * (e - b);
  return ans * (e - b);
}

void comp(int l, int r, int le, int re) {
  if (l > r) return;

  int mid = (l + r) >> 1;

  int best = max(mid + 1, le);
  dp[cur][mid] = dp[cur ^ 1][best] + cost(mid, best - 1);
  for (int i = best; i <= re; i++) {
    if (dp[cur][mid] > dp[cur ^ 1][i] + cost(mid, i - 1)) {
      best = i;
      dp[cur][mid] = dp[cur ^ 1][i] + cost(mid, i - 1);
    }
  }

  comp(l, mid - 1, le, best);
  comp(mid + 1, r, best, re);
}


void solve() {
  int n, b, s, r;
  read(n, b, s, r);

  graph ford(n), back(n);
  for (int i = 0; i < r; i++) {
    int u, v, w;
    read(u, v, w);
    u--; v--;
    ford[u].emplace_back(v, w);
    back[v].emplace_back(u, w);
  }

  auto df = dijkstra(ford, b).second;
  auto db = dijkstra(back, b).second;

  for (int i = 0; i < b; i++)
    dist[i] = df[i] + db[i];

  sort(dist, dist + b);

  for (int i = 1; i < b; i++) {
    dist[i] += dist[i - 1];
  }


  for (int i = 0; i < b; i++)
    dp[cur][i] = inf;
  dp[cur][b] = 0;

  for (int i = 0; i < s; i++) {
    cur ^= 1;
    comp(0, b - 1, 0, b);
    dp[cur][b] = inf;
  }

  cout << dp[cur][0] << endl;
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

