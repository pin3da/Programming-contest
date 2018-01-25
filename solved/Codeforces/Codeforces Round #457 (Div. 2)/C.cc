#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

namespace primes {
  const int MP = 1000001;
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
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  primes::fill_sieve();

  int n, m;
  cin >> n >> m;

  int ans = *lower_bound(primes::primes, primes::primes + primes::num_p, n);

  cout << ans << " " << ans << endl;

  for (int i = 1; i < n - 1; i++) {
    cout << i << " " << (i + 1) << " " << 1 << endl;
  }
  cout << (n - 1) << " " << n  << " " << (ans - n + 2) << endl;

  int last = ans + 1;
  int missing = m - n + 1;
  for (int i = 1; i < n && missing; i++) {
    for (int j = i + 2; j <= n && missing; j++) {
      cout << i << " " << j << " " << last << endl;
      missing--;
    }
  }
  return 0;
}
