using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MAXN = 10001;

vector<int> g[MAXN];
vector<int> g2[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN], visited[MAXN];
stack<int> s;
int ticks, current_scc;

void tarjan_scc(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for (int k=0, m=out.size(); k<m; ++k){
    const int &v = out[k];
    if (d[v] == -1){
      tarjan_scc(v);
      low[u] = min(low[u], low[v]);
    }else if (stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }
  if (d[u] == low[u]){
    int v;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }while (u != v);
    current_scc++;
  }
}

void dfs(int node) {
  if (visited[node]) return;
  visited[node] = 1;
  for (int i = 0; i< g[node].size(); ++i) {
    if (scc[node] != scc[g[node][i]])
      g2[scc[node]].push_back(scc[g[node][i]]);
    dfs(g[node][i]);
  }
}


void solve() {
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < MAXN; ++i) {
    g[i].clear();
    g2[i].clear();
  }
  s = stack<int>();
  memset(stacked, 0, sizeof stacked);
  memset(scc, -1, sizeof scc);
  memset(d, -1, sizeof d);
  memset(visited, 0, sizeof visited);
  ticks = 0;
  current_scc = 0;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
  }

  for (int i = 0; i < n; ++i)
    if (scc[i] == -1)
      tarjan_scc(i);

  for (int i = 0; i < n; ++i)
    if (!visited[i])
      dfs(i);

  vector<int> inc(n, 0);
  for (int i = 0; i < current_scc; ++i)
    for (int j = 0; j < g2[i].size(); ++j)
      inc[g2[i][j]]++;

  int ans = 0;
  for (int i = 0; i < current_scc; ++i) {
    if (inc[i] == 0)
      ans++;
  }
  printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }

  return 0;
}
