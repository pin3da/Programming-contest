#include <bits/stdc++.h>

void solve() {
  long long n;
  std::cin >> n;
  long long ans = 0;
  for (long long i = 2; i * i <= n; ++i) {
    long long j = n / i;
    ans += (i + j) * (j - i + 1) / 2;
    ans += i * (j - i);
  }
  printf("%lld\n", ans);
}

int main() {
  std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
  int tc; std::cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
