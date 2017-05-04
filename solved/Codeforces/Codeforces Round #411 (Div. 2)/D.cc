#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long mod = 1e9 + 7;

long long mod_pow(long long base, long long exp) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  string line; cin >> line;
  long long ans = 0;
  int acc = 0;
  for (int i = 0; i < (int)line.size(); ++i) {
    if (line[i] == 'b') {
      ans += (mod_pow(2, acc) - 1 + mod) % mod;
      ans %= mod;
    } else {
      acc++;
    }
  }
  cout << ans << endl;

  return 0;
}
