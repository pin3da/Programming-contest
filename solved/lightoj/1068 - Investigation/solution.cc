using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

string to_s(int t) {
  stringstream ss;
  ss << t;
  return ss.str();
}

string target;
int k;

int dp[10][2][100][100];

int go(int i, int top, int mod_sum, int mod_prod) {
  if (i == target.size()) {
    return (mod_sum == 0) && (mod_prod == 0);
  }

  if (dp[i][top][mod_sum][mod_prod] != -1)
    return dp[i][top][mod_sum][mod_prod];

  int ans = 0;
  int mmax = top ? (target[i] - '0' ): 9;
  for (int j = 0; j <= mmax; ++j) {
    ans += go(i + 1, top && (j == mmax), (mod_sum + j) % k, (((mod_prod * 10) % k) + j) % k);
  }
  return dp[i][top][mod_sum][mod_prod] = ans;
}

void solve() {
  int a, b;
  cin >> a >> b >> k;
  a--;
  if (k > 99) {
    printf("0\n");
    return;
  }

  target = to_s(b);
  memset(dp, -1, sizeof dp);
  long long ans = go(0, 1, 0, 0);

  target = to_s(a);
  memset(dp, -1, sizeof dp);
  ans -= go(0, 1, 0, 0);
  printf("%d\n", ans);
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}

