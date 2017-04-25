// http://codeforces.com/contest/578/problem/B

using namespace std;
#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl

const int MN = 200002;
const int MK = 20;
unsigned long long dp[MN][MK];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, K, x;
  cin >> n >> K >> x;
  vector<unsigned long long> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];


  unsigned long long best = 0;
  clock_t start = clock();

  while (clock() - start < CLOCKS_PER_SEC) {
    random_shuffle(a.begin(), a.end());
    for (int i = 0; i < MK; ++i)
      dp[n][i] = 0;

    for (int i = n - 1; i >= 0; --i) {
      for (int k = 0; k < MK; ++k) {
        unsigned long long best = a[i] | dp[i + 1][k];
        unsigned long long cur = a[i];
        for (int j = 1; j <= k; ++j) {
          cur *= x;
          best = max(best, cur | dp[i + 1][k - j]);
        }
        dp[i][k] = best;
      }
    }
    best = max(best, dp[0][K]);
  }

  cout << best << endl;

  return 0;
}