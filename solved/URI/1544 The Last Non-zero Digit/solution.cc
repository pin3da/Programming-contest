#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const long long mod = 100000000;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, m;
  while (cin >> n >> m) {
    long long ans = 1;
    for (long long i = 0; i < m; ++i) {
      ans *= n - i;
      while ((ans % 10) == 0) ans /= 10;
      ans %= mod;
    }
    cout << (ans % 10) << endl;
  }
  return 0;
}
