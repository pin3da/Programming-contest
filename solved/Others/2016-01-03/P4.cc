#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


const int MP = 1000001;
char sieve[MP];
long long primes[MP];
int prime_counter;

void fill_sieve() {
  prime_counter = 0;
  memset(sieve, 1, sizeof sieve);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i < MP; ++i) {
    if (sieve[i]) {
      primes[prime_counter++] = i;
      for (int j = i + i; j < MP; j += i)
        sieve[j] = 0;
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
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fill_sieve();
  long long n;
  while (cin >> n && n) {
    cout << totient(n) << endl;
  }
  return 0;
}
