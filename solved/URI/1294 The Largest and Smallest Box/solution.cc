#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double ld;

const ld eps = 1e-7;

ld f(ld w, ld l, ld x) {
  return (w - 2 * x) * (l - 2 * x) * x;
}
ld solve(ld w, ld l) {
  ld a = (l + w) / 6.0;
  ld x = a - sqrt(a * a - (l * w / 12.0));
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ld w, l;
  cout << fixed << setprecision(3);
  while (cin >> l >> w) {
    cout << solve(l, w) + eps << " " << 0.0 << " " << min(w, l) * 0.5 + eps << endl;
  }
  return 0;
}
