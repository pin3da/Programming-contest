#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

const int MP = 1000001;
bool sieve[MP];
long long ans[MP];
long long primes[MP];
int num_p;
void fill_sieve() {
  num_p = 0;
  sieve[0] = sieve[1] = true;
  for (long long i = 2; i < MP; ++i) {
    if (!sieve[i]) {
      primes[num_p++] = i;
      ans[i]++;
      for (long long j = i + i; j < MP; j += i) {
        sieve[j] = true;
        ans[j]++;
      }
    }
  }
}

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

long long acc[MP];

int main() {
  fill_sieve();
  int n, x, y;
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  for (int i = 0; i < MP; ++i) {
    acc[i] = ans[i];
    if (i) acc[i] += acc[i - 1];
    acc[i] %= mod;
  }

  while (cin >> n >> x >> y && (n + x +y)) {
    int d = y - x;
    long long total = acc[d];
    total = (total * mod_pow(2, d - 1)) % mod;
    cout << total << "\n";
  }
  return 0;
}
