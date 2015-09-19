using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

int T;
int fix(vector<vector<int> > &g, int node) {
  int tot = g[node].size();
  int ans = (tot == 0);

  vector<int> cur(g[node].size());
  for (int i = 0; i < g[node].size(); ++i)
    cur[i] = fix(g, g[node][i]);

  sort(cur.begin(), cur.end());
  for (int i = 0; i < g[node].size() && (i * 100) < T * tot; ++i)
    ans += cur[i];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n >> T && (n | T)) {
    vector<vector<int> > g(n + 1);
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      g[t].push_back(i + 1);
    }

    cout << fix(g, 0) << endl;
  }
  return 0;
}
