using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000LL;

long long num_zeros(long long n) {
  int ans = 0;
  long long t = 5;
  while (t <= n) {
    ans += n / t;
    t *= 5;
  }
  return ans;
}

void solve() {
  long long n; cin >> n;
  long long lo = 0, hi = inf;
  bool seen = 0;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    long long f = num_zeros(mid);
    if (f >= n)
      hi = mid, seen |= (n == f);
    else
      lo = mid + 1;
  }
  if (seen)
    printf("%lld\n", lo);
  else
    puts("impossible");
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
