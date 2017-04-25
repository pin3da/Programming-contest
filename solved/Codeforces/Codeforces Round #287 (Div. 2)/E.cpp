// http://codeforces.com/contest/507/problem/E

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

using namespace std;

struct edge {
  int from, to, type;
  bool operator < (const edge &o ) const {
    if (from == o.from)
      if (to == o.to)
        return type < o.type;
      else
        return to < o.to;
    return from < o.from;
  }
};

typedef vector<vector<edge>> graph;

const int inf = 1000000;

vector<int> shortest_path(graph &g, int s) {
  vector<int> d(g.size(), inf);

  d[s] = 0;

  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int cur = q.front();q.pop();
    for (auto &e : g[cur]) {
      if (d[e.to] > d[cur] + 1) {
        d[e.to] = d[cur] + 1;
        q.push(e.to);
      }
    }
  }

  return d;
}

int dp[100000 + 10];

int go(graph &g, int node) {
  if (node == g.size() - 1)
    return dp[node] = 0;

  if (dp[node] != -1)
    return dp[node];

  int best = inf;
  for (auto &e : g[node]) {
    best = min(best, go(g, e.to) + (e.type ^ 1));
  }
  return dp[node] = best;
}


int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  graph g(n);
  int cool = 0;
  map<pair<int, int>, int> in;
  for (int i = 0; i < m; ++i) {
    edge e;
    cin >> e.from >> e.to >> e.type;
    e.from--;e.to--;
    in[make_pair(e.from, e.to)] = e.type;
    cool += e.type;
    g[e.from].push_back(e);
    g[e.to].push_back((edge) {e.to, e.from, e.type});
  }

  vector<int> d1 = shortest_path(g, 0);
  vector<int> d2 = shortest_path(g, n - 1);

  int best = d1[n - 1];
  unordered_set<int> in_sp;

  graph g2(n);
  for (int i = 0; i < n; ++i) {
    for (auto &e : g[i]) {
      if (d1[i] + 1 + d2[e.to] == best) {
        g2[i].push_back(e);
      }
    }
  }

  memset(dp, -1, sizeof dp);
  int ans = go(g2, 0);

  int bad = m - cool;
  bad -= ans;
  cool -= (best - ans);
  cout << cool + ans << endl;

  int cur = 0;
  while (cur != (n - 1)) {
    for (auto &e : g2[cur]) {
      if (dp[cur] == (dp[e.to] + (e.type ^ 1))) {
        if (e.type == 0) {
          if (in.count(make_pair(cur, e.to)))
            cout << cur + 1 << " " << e.to + 1 << " " << 1 << endl;
          else
            cout << e.to + 1<< " " << cur + 1<< " " << 1 << endl;
        } else {
          if (in.count(make_pair(cur, e.to)))
            in[make_pair(cur, e.to)] = 0;
          else
            in[make_pair(e.to, cur)] = 0;
        }
        cur = e.to;
        break;
      }
    }
    // assert(false);
  }

  for (auto &e : in) {
    if (e.second) {
      cout << e.first.first + 1 << " " << e.first.second + 1 << " " << 0 << endl;
    }
  }

  return 0;
}
