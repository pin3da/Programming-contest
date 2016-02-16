#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int C1, C2;
const int MN = 1000 * 2 + 100;

long long dp[MN][MN];

void fill_dp(vector<long long> &t1, vector<long long> &t2) {

  for (int i = 0; i < MN; ++i)
    dp[i][0] = 0;

  for (int i = t1.size() - 1; i >= 0; --i) {
    for (int j = 1; j < MN; ++j) {
      long long op1 = dp[t1[i] + 1][max(0LL, j - (t1[i] - i + 1))] + C1;
      long long op2 = dp[t2[i] + 1][max(0LL, j - (t2[i] - i + 1))] + C2;
      dp[i][j] = min(op1, op2);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, c, t1, t2;
  while (cin >> n >> c >> t1 >> t2) {
    C1 = t1, C2 = t2;
    vector<long long> a(2 * n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i + n] = a[i] + c;
    }

    vector<long long> max1(a.size());
    vector<long long> max2(a.size());
    for (int i = 0; i < a.size(); ++i) {
      max1[i] = upper_bound(a.begin() + i, a.end(), a[i] + t1) - 1 - a.begin();
      max2[i] = upper_bound(a.begin() + i, a.end(), a[i] + t2) - 1 - a.begin();
    }

    max1[a.size() - 1] = a.size() - 1;
    max2[a.size() - 1] = a.size() - 1;

    fill_dp(max1, max2);
    long long best = c;
    for (int i = n - 1; i >= 0; --i) {
      best = min(dp[i][n], best);
    }
    cout << best << endl;
  }
  return 0;
}

