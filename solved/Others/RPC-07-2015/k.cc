using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

const int MN = 1010;
int p[MN];

int fs(int x) {
  return (x == p[x]) ? x : p[x] = fs(p[x]);
}

int dfs(vector<vector<int>> &g, vector<int> &vi, int node) {
  if (vi[node])
    return 0;

  vi[node] = true;
  int ans = 1;
  for (int i = 0; i < g[node].size(); ++i) {
    ans += dfs(g, vi, g[node][i]);
  }
  return ans;
}

int k;
int dp[MN][MN];

int go(vector<pair<int, int>> &a, int i, int cur) {
  if (a.size() == i) {
    if (cur <= k)
      return cur;
    else
      return 0;
  }

  if (dp[i][cur] != -1)
    return dp[i][cur];

  int best = go(a, i + 1, cur);
  for (int j = 0; j <= a[i].second; ++j) {
    if (cur + a[i].first + j > k) break;
    best = max(best, go(a, i + 1, cur + a[i].first + j));
  }
  return dp[i][cur] = best;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, t;
  cin >> n >> k;
  vector<vector<int>> g(n), g2(n);
  for (int i = 0; i < n; ++i)
    p[i] = i;


  vector<int> in_cycle;
  for (int i = 0; i < n; ++i) {
    cin >> t;t--;
    g[i].push_back(t);
    g2[t].push_back(i);

    if (fs(i) == fs(t))
      in_cycle.push_back(i);
    else
      p[fs(i)] = fs(t);
  }


  vector<pair<int,int>> ans;
  for (int i = 0; i < in_cycle.size(); ++i) {
    int node = in_cycle[i];
    vector<int> vi(n, 0);
    int a = dfs(g, vi, node);
    vi.assign(n, 0);
    int b = dfs(g2, vi, node);
    ans.push_back(make_pair(a, b - a));
    // cout << a << " : " << (b - a) << endl;
  }

  memset(dp, -1, sizeof dp);
  cout << go(ans, 0, 0) << endl;
  return 0;
}
