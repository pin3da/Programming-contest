#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 1010;
int lcs[MN][MN];
int dp[MN][MN];
int n_o[MN][30][3]; // next occ

const int mod = 1000007;
int add (int a, int b) {
  int ans = a + b;
  if (ans >= mod)
    ans -= mod;
  return ans;
}

int dfs(string &a, string &b, int i, int j) {
  if(lcs[i][j] == 0)
    return 1;

  if (dp[i][j] != -1) return dp[i][j];

  dp[i][j] = 0;
  for (int k = 0; k < 26; ++k) {
    int x = n_o[i][k][0], y = n_o[j][k][1];
    if (lcs[x][y] == lcs[i][j]) {
      dp[i][j] = add(dp[i][j], dfs(a, b, x + 1, y + 1));
    }
  }
  return dp[i][j];
}

void solve() {
  string a, b;
  cin >> a >> b;
  for (int k = 0; k < 26; ++k) {
    n_o[a.size()][k][0] = a.size();
    n_o[b.size()][k][1] = b.size();
  }

  for (int i = a.size() - 1; i >= 0; --i)
    for (int k = 0; k < 26; ++k)
      if (a[i] == (k + 'a')) n_o[i][k][0] = i;
      else   n_o[i][k][0] = n_o[i + 1][k][0];


  for (int i = b.size() - 1; i >= 0; --i)
    for (int k = 0; k < 26; ++k)
      if (b[i] == (k + 'a')) n_o[i][k][1] = i;
      else   n_o[i][k][1] = n_o[i + 1][k][1];


  for (int i = a.size(); i >= 0; --i) {
    for (int j = b.size(); j >= 0; --j) {
      if (i == a.size() || j == b.size()) {
        lcs[i][j] = 0;
        continue;
      }
      lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1]);
      if (a[i] == b[j])
        lcs[i][j] = max(lcs[i][j], lcs[i + 1][j + 1] + 1);
    }
  }

  int ans;
  memset(dp, -1, sizeof dp);
  ans = dfs(a, b, 0, 0);
  /*for (int i = a.size(); i >= 0; --i) {
    for (int j = b.size(); j >= 0; --j) {
      if (lcs[i][j] == 0) {
        dp[i][j] = 1;
        continue;
      }

      dp[i][j] = 0;
      for (int k = 0; k < 26; ++k) {
        int x = n_o[i][k][0], y = n_o[j][k][1];
        if (lcs[x][y] == lcs[i][j]) {
          dp[i][j] = add(dp[i][j], dp[x + 1][y + 1]);
        }
      }
    }
  }*/

  printf("%d\n", ans);
}

int main () {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
