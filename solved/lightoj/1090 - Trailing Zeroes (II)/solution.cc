using namespace std;
#include <bits/stdc++.h>

long long f(int val, long long p) {
  long long ans = 0;
  long long b = p;
  while (b <= val) {
    ans += val / b;
    b *= p;
  }
  return ans;
}

long long get(int n, int r, int p, int q, int cur) {
  long long ans = f(n, cur) - f(r, cur) - f(n - r, cur);
  int exp = 0;
  while (p % cur == 0) {
    exp++;
    p /= cur;
  }

  ans += q * exp;
  return ans;
}

void solve() {
  int n, r, p, q;
  cin >> n >> r >> p >> q;
  printf("%lld\n", min(get(n, r, p, q, 2), get(n, r, p, q, 5)));
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
