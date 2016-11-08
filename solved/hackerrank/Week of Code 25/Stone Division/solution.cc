#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout << #x << " = " << (x) << endl

int m;
long long s[11];

map<long long, int> dp;
int go(long long n) {
  if (n == 1) return 0;

  if (dp.count(n)) return dp[n];
  vector<int> mex(11);
  for (int i = 0; i < m; ++i) {
    if (n % s[i]) continue;
    int to = (s[i] & 1) ? go(n / s[i]) : 0;
    if (to < 11)
      mex[to] = 1;
  }
  for (int i = 0; i < 11; ++i)
    if (!mex[i]) return dp[n] = i;
  assert(false);
}

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }

  int ans = go(n);
  puts(ans != 0 ? "First" : "Second");
  return 0;
}
