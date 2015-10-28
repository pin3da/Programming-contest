#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n_zeroes(ll n) {
  ll ans = 0;
  while (n > 0) {
    n /= 5;
    ans += n;
  }
  return ans;
}

void solve(ll q) {
  ll lo = -1, hi = 1000000001;
  while (hi - lo > 1) {
    ll mid = (hi + lo) >> 1;
    if (n_zeroes(mid) < q)
      lo = mid;
    else
      hi = mid;
  }
  // cout<<endl<< n_zeroes(hi) << endl;
  if (n_zeroes(hi) != q)
    printf("impossible\n");
  else
    printf("%lld\n", hi);
}

int main() {
  int tc; scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    ll q;
    scanf("%lld", &q);
    printf("Case %d: ", i + 1);
    solve(q);
  }
  return 0;
}
