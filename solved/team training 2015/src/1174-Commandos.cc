#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int> g[], int s, int d) {
  queue<int> Q;
  vector<int> dist(n, -1);
  dist[s] = 0;
  Q.push(s);

  while(!Q.empty()) {
    int t = Q.front(); Q.pop();
    
    for (int i = 0; i < g[t].size(); i++)
      if (dist[g[t][i]] == -1) {
	dist[g[t][i]] = dist[t] + 1;
	Q.push(g[t][i]);
      }
  }

  // for (int i = 0; i < n; i++)
  //   cout << " " << dist[i];
  // cout << endl;
  return dist;
}

int solve(int n, int m) {
  // if (m == 1)
  //   return 1;

  vector<int> g[n];
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s, d;
  scanf("%d %d", &s, &d);

  vector<int> put = bfs(n, g, s, d);
  vector<int> run = bfs(n, g, d, s); run[s] = 0;

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, put[i] + run[i]);
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("Case %d: %d\n", i + 1, solve(n, m));
  }
  return 0;
}
