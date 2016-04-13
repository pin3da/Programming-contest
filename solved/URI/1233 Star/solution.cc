#include <bits/stdc++.h>

using namespace std;

const long long MN = 1000 * 100;
bool sieve[MN];
long long primes[MN];

void fillp() {
  memset(sieve, 0, sizeof sieve);
  sieve[1] = sieve[0] = 1;
  int p = 0;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      primes[p++] = i;
      for (long long j = i + i; j < MN; j += i)
        sieve[j] = true;
    }
  }
}


long long totient(long long n) {
  if (n == 1) return 0;
  long long ans = n;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      while ((n % primes[i]) == 0) n /= primes[i];
      ans -= ans / primes[i];
    }
  }
  if (n > 1) {
    ans -= ans / n;
  }
  return ans;
}

int main() {
  fillp();

  long long n;
  while (cin >> n) {
    cout << (totient(n) >> 1) << endl;
  }

  return 0;
}

