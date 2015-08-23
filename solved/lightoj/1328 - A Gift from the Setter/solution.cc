using namespace std;
#include <bits/stdc++.h>

const long long mod = 1000007;

void solve() {
  int k, c, n, a;
  cin >> k >> c >> n >> a;
  vector<long long> s;
  s.push_back(a);
  for (int i = 0; i < n - 1; ++i)
    s.push_back((s.back() * k + c) % mod);
  sort(s.begin(), s.end());

  vector<long long> p = s;
  for (int i = 1; i < n; ++i)
    s[i] += s[i - 1];

  long long ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    ans += s[n - 1] - s[i] - (n - i - 1) * p[i];
  }
  printf("%lld\n", ans);
}


int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
