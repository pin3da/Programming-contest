// http://codeforces.com/contest/489/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define endl '\n'


const int MN = 3333;
long long ways[MN][MN];
vector<int> g[MN];
int n,m;

void dfs(int &ori, int node, int depth) {
  if (depth == 2)
    ways[ori][node]++;
  else
    for (int i = 0; i < g[node].size(); ++i)
      dfs(ori, g[node][i], depth + 1);
}

int main() { ___

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
  }


  for (int i = 0; i < n; ++i)
    dfs(i, i, 0);


  long long ans = 0;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j)
        ans += (ways[i][j] * (ways[i][j] - 1) / 2LL);

  cout << ans << endl;

  return 0;
}