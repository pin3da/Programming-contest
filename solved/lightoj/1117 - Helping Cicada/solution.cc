using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve() {
  long long n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i)
    cin >> a[i];

  int target = (1 << m) - 1;
  long long total = 0;
  for (int mask = 1; mask <= target; ++mask) {
    int ele = __builtin_popcount(mask) & 1;
    ele     =  ele ? 1 : - 1;
    long long den = 1;
    for (int i = 0; i < m; ++i) if ((mask >> i) & 1) {
      long long g = __gcd<long long>(a[i], den);
      den = (den * a[i]) / g;
    }
    total += ele * (n / den);
  }
  printf("%lld\n", n - total);
}

int main() {
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
