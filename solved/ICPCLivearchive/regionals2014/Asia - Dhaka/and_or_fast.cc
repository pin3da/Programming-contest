using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int log_ceil(long long x) {
  int ans = 0;
  while ((1LL << ans) <= x) ans++;
  return ans;
}

void solve() {
  long long a, b;
  cin >> b >> a;
  long long ans_or = 0, ans_and = 0;
  int lb = log_ceil(b), la = log_ceil(a);
  if (la != lb) {
    printf("%lld %lld\n", (1LL << la) - 1, 0);
    return;
  }

  for (int i = la; i >= 0; --i) {
    int ba = (a >> i) & 1,
        bb = (b >> i) & 1;

    if (bb != ba) {
      ans_or |= (1LL << (i + 1)) - 1;
      break;
    }

    if (ba && bb) {
      ans_or |= (1LL << i);
      ans_and |= (1LL << i);
    }
  }
  printf("%lld %lld\n", ans_or, ans_and);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
