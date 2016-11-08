#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl
#define forall(it, x) for (typeof x.begin() it = x.begin(); it != x.end(); ++it)
const int MN = 1005;
const int ZZ = 30; 

vector<int> g[MN][ZZ];
string A;

typedef long double ld;
int n;

int seen[MN][222];
ld dp[MN][222];

ld go(int node, int ti) {

  if (node == (n - 1)) return 1.0;
  if (ti == A.size()) return 0.0;
  
  if (seen[node][ti])
    return dp[node][ti];

  seen[node][ti] = true;
  
  int x = A[ti] - 'A';
  ld ans = 0;
  if (g[node][x].size() == 0) return dp[node][ti] = go(node, ti + 1);
  for (int i = 0; i < g[node][x].size(); ++i) {
    ans += go(g[node][x][i], ti + 1);
  }
  return dp[node][ti] = ans / g[node][x].size();
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v; char w;
    cin >> u >> v >> w;
    u--;v--;
    g[u][w - 'A'].push_back(v);
    g[v][w - 'A'].push_back(u);
  }
  cin >> A;
 
  memset(seen, 0, sizeof seen); 
  cout << fixed << setprecision(5);
  cout << go(0, 0) * 100.0 << endl;
  return 0;
}
