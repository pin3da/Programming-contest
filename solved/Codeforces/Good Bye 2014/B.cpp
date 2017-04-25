// http://codeforces.com/contest/500/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void dfs(int node, vector< vector<char> >  &g, vector<int> &v, vector<pair<int, int> > &p, vector<int> &ans) {
  if (v[node]) return;

  v[node] = true;
  ans.push_back(node);
  for (int i = 0; i < g.size(); i++) {
    if (g[node][i] == '1')
      dfs(i, g, v, p, ans);
  }
}


int main() { ___

  int n;
  cin >> n;
  vector<pair<int, int> > p(n);
  vector< vector<char> > g(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first;
    p[i].second = i;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> g[i][j];


  vector<vector<int> > reach(n);
  for (int i = 0; i < n; ++i) {
    vector<int> vis(n, false), ans;
    dfs(i, g, vis, p, ans);
    sort(ans.begin(), ans.end());
    reach[i] = ans;
    // D(ans.size());
  }


  sort(p.begin(), p.end());
  vector<int> q(n);
  vector<int> chosen(n, false);
  for (int i = 0; i < n; i++) {
    int j = 0;
    int cur = p[i].second;
    while (j < reach[cur].size() and chosen[reach[cur][j]]) ++j;
    assert(j < reach[cur].size());
    q[reach[cur][j]] = p[i].first;
    chosen[reach[cur][j]] = true;
  }

  for (int i = 0; i < n; ++i)
    cout << q[i] << " ";

  cout << endl;


  return 0;
}
