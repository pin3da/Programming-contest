using namespace std;
#include <bits/stdc++.h>

typedef unsigned long long ull;

ull f(ull n) {
  return n - (n / 10);
}

ull lower(ull n) {
  ull lo = n, hi = n * 10;
  while (lo < hi) {
    ull mid = (lo + hi) >> 1;
    if (f(mid) >= n)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

ull upper(ull n) {
  ull lo = n, hi = n * 10;
  while (lo < hi) {
    ull mid = (lo + hi + 1) >> 1;
    if (f(mid) <= n)
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}


void solve() {
  ull n;
  cin >> n;
  ull ans1 = lower(n);
  ull ans2 = upper(n);
  if (ans1 != ans2)
    printf("%llu %llu\n", ans1, ans2);
  else
    printf("%llu\n", ans1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
