#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 10000001;

struct ht {
  int _s[(MN + 10) >> 5];
  int len;
  ht() {
    memset(_s, 0, sizeof _s);
    len = 0;
  }
  void set(int id) {
    len++;
    _s[id >> 5] |= (1LL << (id & 31));
  }
  bool test(int id) {
    return _s[id >> 5] & (1LL << (id & 31));
  }
};

ht sieve;
int p[MN / 10];
int primes;

void fill_sieve() {
  primes = 0;
  for (int i = 2; i < MN; ++i) {
    if (!sieve.test(i)) {
      p[primes++] = i;
      for (int j = i + i; j < MN; j += i)
        sieve.set(j);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fill_sieve();
  long long n;
  while (cin >> n) {
    while ((n & 1) == 0) n >>= 1;
    long long ans = 1;
    for (int i = 0; i < primes && p[i] * p[i] <= n; ++i) {
      int exp = 1;
      while ((n % p[i]) == 0) {
        n /= p[i];
        exp++;
      }
      ans *= exp;
    }
    if (n > 1) ans <<= 1;
    cout << ans << endl;
  }
  return 0;
}
