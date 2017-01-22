#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


int findv(vector<int> &t, long long val) {
  auto it = lower_bound(t.begin(), t.end(), val);
  if ((*it) > val && (it != t.begin())) it--;
  return it - t.begin();
}


const int MN = 123456;

long long dp[MN];
long long go(vector<int> &t, int id) {
  if (id == 0) return 0;

  if (dp[id] != -1)
    return dp[id];

  long long best = go(t, id - 1) + 20;
  best = min(best, go(t, findv(t, t[id] - 90)) + 50);
  best = min(best, go(t, findv(t, t[id] - 1440)) + 120);
  return dp[id] = best;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;

  vector<int> t(n + 1);
  t[0] = -1;
  for (int i = 0; i < n; ++i)
    cin >> t[i + 1];

  memset(dp, -1, sizeof dp);
  long long a = 0;
  for (int i = 1; i < n + 1; ++i) {
    long long b = go(t, i);
    long long ans = max(0LL, b - a);
    cout << ans << endl;
    a += ans;
  }
  return 0;
}
