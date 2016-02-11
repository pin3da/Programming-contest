#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double d_type;

d_type R, r, H;
const d_type pi = acos((d_type)-1);
const d_type eps = 1e-9;

d_type volume(d_type h) {
  d_type B = r + ((R - r) / H) * h;
  return ((pi * h) / 3.0 ) * (B * B + B * r + r * r);
}

void solve() {
  int n;
  cin >> n;
  d_type L;
  cin >> L;
  cin >> r >> R >> H;
  L /= n;
  d_type lo = eps, hi = H;
  int iter = 1000;
  while (lo - eps < hi && iter > 0) {
    d_type mid = (lo + hi) * 0.5;
    d_type v_mid = volume(mid);
    if (fabs(v_mid - L) < eps)
      break;

    if (v_mid < L)
      lo = mid;
    else
      hi = mid;
    iter--;
  }

  cout << fixed << setprecision(2) << lo << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
