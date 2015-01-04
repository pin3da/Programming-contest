using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 2002;
const int oo = 1000000000;
struct edge{
  int v, w; edge(){} edge(int v, int w) : v(v), w(w) {}
};
vector<edge> g[MN];
int d[MN];
int p[MN];

int memo[MN];
int reachable(int node, vector<int> &visited) {
/*
 *  if (node == 0)
 *    return true;
 *
 *  if (memo[node] != -1)
 *    return memo[node];
 */

  if (node == 0)
    return true;

  if (visited[node])
    return false;

  visited[node] = true;
  int ans = 0;
  for (int i = 0; i < g[node].size(); ++i) {
    if (reachable(g[node][i].v, visited))
      ans = true;
  }
  return ans;
}

bool bellman(int s, int n){
  for (int i=0; i<n; ++i){
    d[i] = oo;
    p[i] = -1;
  }
  d[s] = 0;
  for (int i=0, changed = true; i<n-1 && changed; ++i){
    changed = false;
    for (int u=0; u<n; ++u){
      for (int k=0; k<g[u].size(); ++k){
        int v = g[u][k].v, w = g[u][k].w;
        if (d[u] + w < d[v]){
          d[v] = d[u] + w;
          p[v] = u;
          changed = true;
        }
      }
    }
  }
  for (int u=0; u<n; ++u){
    for (int k=0; k<g[u].size(); ++k){
      int v = g[u][k].v, w = g[u][k].w;
      if (d[u] + w < d[v]){
        vector<bool> seen(n, false);
        deque<int> cycle;
        int cur = v;
        for (; !seen[cur]; cur = p[cur]){
          seen[cur] = true;
          cycle.push_front(cur);
        }
        cycle.push_front(cur);
        //there's a negative cycle that goes from
        //cycle.front() until it reaches itself again
        // printf("Negative weight cycle reachable from s:\n");
        int i = 0;
        do{
          vector<int> visited(n, false);
          if (cycle[i] && reachable(cycle[i], visited))
            return false;
          // printf("%d ", cycle[i]);
          i++;
        }while(cycle[i] != cycle[0]);
         // printf("\n");

        // return false;
      }
    }
  }
  return true;
}

void solve() {
  int n, m;
  cin >> n >> m;

  memset(memo, -1, sizeof memo);
  for (int i = 0; i < n + 1; ++i)
    g[i].clear();

  int u, v , w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    g[u].push_back(edge(v, w));
  }

  int ans = bellman(0, n);
  if (!ans)
    cout << "possible" << endl;
  else
    cout << "not possible" << endl;



}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }

  return 0;
}
