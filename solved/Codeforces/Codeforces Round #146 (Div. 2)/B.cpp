// http://codeforces.com/contest/236/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#ifndef BMO
#define endl '\n'
#define _io ios_base::sync_with_stdio(false);cin.tie(NULL);
#else
#define _io
#endif



const int MP = 1000000 + 10;

char sieve[MP];
int primes[MP];
int prime_counter;
int divs[MP];
long long pd[MP];
long long ans;

void fill_sieve(){
  prime_counter = 0;
  ans = 0;
  memset(sieve, 1, sizeof sieve);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i < MP; ++i) {
    if (sieve[i]) {
      primes[prime_counter++] = i;
      divs[i] = 1;
      ans += i;
      for (int j = i + i; j < MP; j += i)
        sieve[j] = 0;
    }
  }
}


void fill_divs() {
  divs[1] = 1;
  for (int i = 2; i < MP; ++i) {
    int ans = 1, cur = 0;
    int t = i;
    while (primes[cur] * primes[cur] <= t) {
      int ex = 0;
      while ((t % primes[cur]) == 0) {
        ex++; t /= primes[cur];
      }
      ans *= (ex + 1);
      cur++;
    }

    if (t > 1)
      ans *= 2;
    divs[i] = ans;
  }
}

const long long mod =  1 << 30;

void solve(int a, int b, int c) {
  long long ans = 0;
  for (int i = 1; i <= a; ++i)
    for (int j = 1; j <= b; ++j)
      for (int k = 1; k <= c; ++k)
        ans = (ans + divs[i * j * k]) % mod;
  cout << ans << endl;
}


int main() { _io
  fill_sieve();fill_divs();
  int a, b, c;
  while (cin >> a >> b >> c) {
    solve(a, b, c);
  }
  return 0;
}
