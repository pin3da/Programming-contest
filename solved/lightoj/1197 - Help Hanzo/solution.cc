#include <bits/stdc++.h>

using namespace std;

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

  // Finds prime numbers between a and b, using basic primes up to sqrt(b)
  long long seg_sieve(long long a, long long b) {
    long long ant = a;
    a = max(a, 3LL);
    vector<bool> pmap(b - a + 1);
    long long sqrt_b = sqrt(b);
    for (int i = 0; i < num_p; ++i) {
      long long p = primes[i];
      if (p > sqrt_b) break;
      long long j = (a + p - 1) / p;
      for (long long v = (j == 1) ? p + p : j * p; v <= b; v += p) {
        pmap[v - a] = true;
      }
    }
    long long ans = 0;
    if (ant == 2) ans++;
    int start = a % 2 ? 0 : 1;
    for (int i = start, I = b - a + 1; i < I; i += 2)
      if (pmap[i] == false)
        ans++;
    return ans;
  }
}

void solve() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  if (a == 1 && b == 1) printf("0\n");
  else {
    if (a == 1) a++;
    printf("%d\n", (int)primes::seg_sieve(a, b));
  }
}


int main() {
  int tc;
  scanf("%d", &tc);
  primes::fill_sieve();
  for (int i = 0; i < tc; i++) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
