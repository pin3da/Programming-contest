#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long mod = 1000 * 1000 * 1000 + 7;
const int MN = 1000 + 100 + 10 + 1;

long long fac[MN];

long long mod_pow(long long base, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  fac[0] = fac[1] = 1;
  for (int i = 2; i < MN; ++i)
    fac[i] = (fac[i - 1] * i) % mod;
  while (cin >> line) {
    vector<int> f(30);
    for (auto &i : line)
      f[i - 'A']++;
    long long ans = fac[line.size()];
    long long den = 1;
    for (auto &i : f) den = (den * fac[i]) % mod;
    ans = (ans * mod_pow(den, mod - 2)) % mod;
    cout << ans << endl;
  }
  return 0;
}
