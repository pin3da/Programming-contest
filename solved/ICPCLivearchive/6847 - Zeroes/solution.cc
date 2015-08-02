using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const long long max_d = 7450580596923828125LL;

long long f(long long x, int p = 5) {
  long long ans = 0;
  while (x) {
    ans += x / p;
    x /= p;
  }
  return ans;
}

void solve(long long &lo, long long &hi) {
  long long ans = f(hi) - f(lo) + 1;
  for (long long d = 25; d <= hi; d *= 5) {
    ans -= (hi / d)  - (lo / d);
    if (d == max_d) break;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long lo, hi;
  while (cin >> lo >> hi and (lo + hi)) {
    solve(lo, hi);
  }

  return 0;
}

