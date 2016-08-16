#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int n, p;

const long long mod = 1000LL * 1000LL * 1000LL + 7;

long long mod_pow(long long b, long long e, long long m) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % m;
    b = (b * b) % m;
    e >>= 1;
  }
  return ans;
}

const int MN = 55;
long long dp[MN][MN];

long long go(int el, int mo) {
  if (el >= mo) return 0;
  if (el == 1) return mo - 1;

  if (dp[el][mo] != -1) return dp[el][mo];
  long long ans = 0;
  for (int i = 1; i < mo; ++i) {
    ans = (ans + go(el - 1, mo - i)) % mod;
  }
  return dp[el][mo] = ans;
}

void solve() {
  cin >> n >> p;
  if (n >= p) {
    cout << 0 << endl;
    return;
  }
  memset(dp, -1, sizeof dp);
  long long ans = (go(n, p) * n) % mod;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}
