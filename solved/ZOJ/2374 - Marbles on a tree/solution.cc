using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int ans;

int solve(vector<vector<int>> &g, vector<int> &val, int node) {
  int c = val[node] - 1;
  for (int i = 0; i < g[node].size(); ++i) {
    int cur = solve(g, val, g[node][i]);
    c += cur;
    ans += fabs(cur);
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<vector<int>> g(n);
    vector<int> in(n);
    vector<int> val(n);
    int u;
    for (int i = 0; i < n; ++i) {
      cin >> u;
      u--;
      int t, v;
      cin >> val[u] >> t;
      for (int j = 0; j < t; ++j) {
        cin >> v;
        v--;
        g[u].push_back(v);
        in[v]++;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (in[i] == 0) {
        ans = 0;
        solve(g, val, i);
        cout << ans << endl;
        break;
      }
    }
  }
  return 0;
}

