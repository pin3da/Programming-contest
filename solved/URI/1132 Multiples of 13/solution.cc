#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long f(long long x) {
  return ( x * (x + 1)) >> 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x, y;
  cin >> x >> y;
  if (y < x) swap(x, y);

  long long ans = f(y) - f(x - 1);

  ans -= f(y / 13) * 13;
  if (x > 2) ans += f((x - 1) / 13) * 13;
  cout << ans << endl;
  return 0;
}
