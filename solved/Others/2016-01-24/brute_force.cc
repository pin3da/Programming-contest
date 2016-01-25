#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 10000;
const long long mod = 1000000007LL;

long long fib[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  fib[1] = 1;
  for (int i = 2; i < MN; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];

  int a, b, n;
  while (cin >> a >> b >> n) {
    if ((a + b + n) == 0) break;
    if (b < a) swap(a, b);
    long long ans = 0;
    int k0 = b - a;
    int k1 = k0 + 1;
    for (int i = 0; i < n; ++i) {
      int c = a + i;
      ans += fib[k0] * fib[c] * fib[c - 1] + fib[k1] * fib[c] * fib[c];
    }
    cout << ans << endl;
  }

  return 0;
}
