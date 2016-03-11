#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

typedef long double dtype;

dtype dp[2][6];

dtype go(vector<dtype> &p, int n, int ant) {
  if (n == 0)
    return 0;
  dtype ans = 0;
  for (int i = 0; i < 6; ++i) {
    if (i == ant) continue;
    ans += go(p, n - 1, i) + (i + 1) * p[i];
  }
  return ans;
}

int main() {
  vector<dtype> p(6);
  for (auto &i : p)
    cin >> i;
  int n;
  cin >> n;
  int t = 0;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < 6; ++i)
    dp[1][i] = (i + 1) * p[i];

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 6; ++j) {
      dp[t][j] = 0;
      for (int k = 0; k < 6; ++k) {
        if (k == j) continue;
        dp[t][j] += (dp[t ^ 1][k] + (j + 1)) * p[j];
      }
    }
    t ^= 1;
  }

  t ^= 1;
  dtype total = 0, otro = go(p, n, -1);
  for (int i = 0; i < 6; ++i) {
    total += dp[t][i];
  }
  cout << total << endl;
  cout << otro << endl;
  return 0;
}
