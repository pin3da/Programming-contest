#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long dp[44];
long long go(int n) {
  if (n == 0) return 1;
  if (n < 0) return 0;
  if (dp[n] != -1) return dp[n];
  return dp[n] = go(n - 1) + go(n - 2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  memset(dp, -1, sizeof dp);
  while (cin >> n && n) {
    cout << go(n) << endl;
  }
  return 0;
}
