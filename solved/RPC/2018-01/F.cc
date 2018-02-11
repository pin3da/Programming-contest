#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);   debug_out(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#define endl '\n'
#endif

const int MN = 444;
double dp[MN][MN];

double go(int a, int b, int k) {
  if (k == 0) return a;

  if (dp[a][k] > -1) return dp[a][k];
  double &ans = dp[a][k];
  if (b)
    ans = 0.5 * go(a + 1, b - 1, k - 1) + 0.5 * go(a, b, k - 1);
  else
    ans = 0.5 * go(a - 1, b + 1, k - 1) + 0.5 * go(a, b, k - 1);
  return ans;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;

  while (cin >> n >> k) {
    for (int i = 0; i < MN; i++) {
      for (int j = 0; j < MN; j++) {
        dp[i][j] = -3;
      }
    }
    cout << fixed << setprecision(8) << go(0, n, k) << endl;
  }

  return 0;
}
