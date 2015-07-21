using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

long long fun(long long n, long long x, long long y, long long b) {
  return x * (n - b) - b * y;
}

long long fun_dec(long long n, long long x, long long y) {
  long long lo = 0, hi = n;
  while (lo < hi) {
    if (lo + 1 == hi) {
      if (fun(n, x, y, hi) > 0)
        lo = hi;
      break;
    }
    long long mid = (lo + hi) >> 1;
    if (fun(n, x, y, mid) > 0) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  return fun(n, x, y, lo);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, m, x, y;
  int cc;
  while (cin >> n >> m) {
    long long ans = 1LL << 60;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y;
      long long cur = fun_dec(n, x, y);
      if (cur < ans) {
        ans = cur;
        cc = i;
      }
    }

    // long long tmp = ((x * n + x + y - 1) / (x + y)) - 1;
    // ans = min(ans, fun(n, x, y, tmp));
    cout << ans << endl;
    // cout << cc << endl;
  }

  return 0;
}
