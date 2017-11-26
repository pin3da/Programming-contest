#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 1123;
const long long MOD = 1e9 + 7;

long long ways[MN][MN];
long long fact[MN];

namespace primes {
  const int MP = 100001;
  bool sieve[MP];
  long long primes[MP];
  int num_p;
  void fill_sieve() {
    num_p = 0;
    sieve[0] = sieve[1] = true;
    for (long long i = 2; i < MP; ++i) {
      if (!sieve[i]) {
        primes[num_p++] = i;
        for (long long j = i * i; j < MP; j += i)
          sieve[j] = true;
      }
    }
  }

  vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> ans;
    if (n == 0) return ans;
    for (int i = 0; primes[i] * primes[i] <= n; ++i) {
      if ((n % primes[i]) == 0) {
        int expo = 0;
        while ((n % primes[i]) == 0) {
          expo++;
          n /= primes[i];
        }
        ans.emplace_back(primes[i], expo);
      }
    }

    if (n > 1) {
      ans.emplace_back(n, 1);
    }
    return ans;
  }
}

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  ways[0][0] = 1;
  fact[0] = 1;
  for (int i = 1; i < MN; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    for (int j = 1; j < MN; j++) {
      ways[i][j] = ways[i - 1][j] + ways[i - 1][j - 1];
      if (ways[i][j] > MOD)
        ways[i][j] -= MOD;
    }
  }

  primes::fill_sieve();
  int n;
  cin >> n;
  while (n--) {
    int val, y;
    cin >> val >> y;
    vector<pair<int, int>> factors = primes::factor(val);
    long long ans = go(factors, val, y);
    ans = (ans  * mod_pow(2, y - 1)) % MOD;
    cout << ans << endl;
  }
  return 0;
}
