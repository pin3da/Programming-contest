#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

typedef vector<vector<int>> graph;

const int MN = 100000 + 100;
int dist[MN];
int pi[MN];

int further(graph &g, int start) {
  deque<int> s;
  fill(dist, dist + MN, MN);
  fill(pi, pi + MN, -1);

  dist[start] = 0;
  s.push_back(start);
  while (!s.empty()) {
    int cur = s.front(); s.pop_front();
    for (int i = 0; i < int(g[cur].size()); i++) {
      int to = g[cur][i];
      if (dist[to] > dist[cur] + 1) {
        dist[to] = dist[cur] + 1;
        pi[to] = cur;
        s.push_back(to);
      }
    }
  }
  int n = g.size();

  return max_element(dist, dist + n) - dist;
}

void solve() {
  int n; cin >> n;
  if (n == 1) {
    cout << "0 1 1" << endl;
    return;
  }
  graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int start = further(g, 0);
  int end = further(g, start);

  deque<int> path;
  path.push_back(end);
  while (pi[end] != -1) {
    path.push_back(pi[end]);
    end = pi[end];
  }

  while (path.size() > 2) {
    path.pop_front();
    path.pop_back();
  }

  sort(path.begin(), path.end());
  int target = 0;
  for (int i = 0; i < int(path.size()); i++)
    target = max(target, dist[path[i]]);

  cout << target << " " << path.size();
  for (int i = 0; i < int(path.size()); i++) {
    cout << " " << path[i] + 1;
  }
  cout << endl;
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

