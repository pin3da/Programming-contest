#include<bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x << " = " << x << endl
using namespace std;

const long long mod = 1000003;
const int MN = 1000000 + 100;

long long fact[MN];
long long fact_inv[MN];

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  fact[0] = 1;
  fact_inv[0] = 0;
  for (int i = 1; i < MN; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
    fact_inv[i] = mod_pow(fact[i], mod - 2);
    fact_inv[i] = (fact_inv[i] + fact_inv[i - 1]) % mod;
  }

  int tc; cin >> tc;
  while (tc--) {
    int tmp; cin >> tmp;
    cout << (fact[tmp] * fact_inv[tmp]) % mod << endl;
  }
  return 0;
}
