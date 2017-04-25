// http://codeforces.com/contest/557/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

bool bipartite(vector<vector<int>> &g, vector<int> &vi, vector<int> &col,
       vector<int> &cc, int node, int cur, int c) {
  if (vi[node])
    return cur == col[node];

  vi[node] = true;
  col[node] = cur;
  cc[node] = c;
  for (int i = 0; i < g[node].size(); ++i) {
    if (!bipartite(g, vi, col, cc, g[node][i], cur ^ 1, c))
      return false;
  }
  return true;
}
int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> vi(n), col(n), cc(n);
  int _cc = 0;
  for (int i = 0; i < n; ++i) {
    if (!vi[i]) {
      if (!bipartite(g, vi, col, cc, i, 0, _cc)) {
        cout << "0 1" << endl;
        return 0;
      }
      _cc++;
    }
  }

  map<pair<int, int>, long long> frec;
  for (int i = 0; i <  n; ++i) {
    frec[make_pair(cc[i], col[i])]++;
  }

  long long ans = 0;
  for (const auto &it : frec) {
    ans += (it.second * (it.second - 1)) / 2;
  }

  if (ans > 0) {
    cout << 1 << " " << ans << endl;
    return 0;
  }

  vector<vector<int>> same_cc(_cc + 1);

  for (int i = 0; i < n; ++i) {
    same_cc[cc[i]].push_back(i);
  }

  int possible = 0;
  for (auto &it : same_cc) {
    int colors = 0;
    for (auto &jt : it) {
      colors |= (col[jt] + 1);
    }
    if (colors == 3) {
      possible++;
    }
  }

  if (possible) {
    long long tmp = possible;
    cout << 2 << " " << tmp * (n - 2) << endl;
    return 0;
  }


  long long tmp =  n;
  cout << 3 << " " << (tmp * (tmp - 1) * (tmp - 2)) / 6 << endl;

  return 0;
}
