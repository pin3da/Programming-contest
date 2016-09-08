#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = (100000 + 100) * 2;
const long long mod = 1e9 + 7;

long long tri[MN];

long long fun(long long x) {
  return (x * (x + 1)) >> 1;
}

long long mod_pow(long long b, long long e, long long m) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % m;
    b = (b * b) % m;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  tri[0] = 1;
  for (int i = 1; i < MN; ++i) {
    tri[i] = ((fun(i + 1) % mod) * tri[i - 1]) % mod;
  }
  int d; cin >> d;
  while (d--) {
    int m, a; cin >> m >> a;
    cout << (tri[m + a] * mod_pow(tri[a], mod - 2, mod)) % mod << endl;
  }
  return 0;
}
