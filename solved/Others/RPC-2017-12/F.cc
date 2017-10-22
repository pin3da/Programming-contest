#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

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

const long long inf = 1000000LL * 10000000LL;

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

vector<int> next_ints() {
  string line; getline(cin, line);
  stringstream ss(line);
  vector<int> ans;
  int tmp;
  while (ss >> tmp) ans.push_back(tmp);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto in = next_ints();
  int tc = in[0];
  for (int tid = 1; tid <= tc; tid++) {
    int n, t;
    auto in = next_ints();
    n = in[0], t = in[1];
    graph g(n);
    for (int i = 0; i < n; i++) {
      auto in = next_ints();
      int u = in[0];
      for (int i = 1; i < in.size(); i += 2) {
        g[u].emplace_back(in[i], in[i + 1]);
      }
    }
    if (t) {
      in = next_ints();
      for (int i = 0; i < in.size(); i += 2) {
        int u, v;
        u = in[i]; v = in[i + 1];
        g[u].emplace_back(v, 0);
        g[v].emplace_back(u, 0);
      }
    }
    int start, end;
    in = next_ints();
    start = in[0], end = in[1];
    auto ans = dijkstra(g, start);
    cout << "Case #" << tid << ": ";
    if (ans.second[end] < inf) {
      cout << ans.second[end] << endl;
      deque<int> path;
      auto pi = ans.first;
      while (end != start) {
        path.push_front(end);
        end = pi[end];
      }
      path.push_front(end);
      for (int i = 0; i < path.size(); i++) {
        if (i) cout << " ";
        cout << path[i];
      }
      cout << endl;
    } else {
      cout << "Path does not exist" << endl;
    }

  }

  return 0;
}
