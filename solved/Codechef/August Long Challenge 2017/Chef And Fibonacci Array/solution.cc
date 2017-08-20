#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1000000007LL;

long long add(long long x, long long y) {
  return (x + y) % mod;
}

const int base = 100 * 3;
int dp[base][2 * base][2 * base];

long long go(vector<int> &arr, int id, int ext_a, int ext_b) {
  if (id + 2 >= (int)arr.size()) return 1;
  int A = ext_a + base, B = ext_b + base;
  if (dp[id][A][B] != -1) return dp[id][A][B];
  long long ans = 0;
  int ops = min(arr[id] + ext_a, arr[id + + 1] + ext_b);
  for (int i = 0; i <= ops; i++)
    ans = add(ans, go(arr, id + 1, ext_b - i, i));
  return dp[id][A][B] = ans;
}


void solve() {
  int n; cin >> n;
  vector<int> a(base);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  memset(dp, -1, sizeof dp);
  long long ans = go(a, 0, 0, 0);
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
