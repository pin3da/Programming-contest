// http://codeforces.com/contest/546/problem/D

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MP = 5000001;

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
  for (int i = 2; i < MP; ++i) {
    int t = i;
    for (int j = 0; primes[j] * primes[j] <= i; ++j) {
      if (i % primes[j] == 0 && i != primes[j]) {
        divs[i] += divs[i / primes[j]] + 1;
        break;
      }
    }
    pd[i] = pd[i - 1] + divs[i];
  }
}

void solve(int n) {
  int a, b;
  while (n--) {
    cin >> a >> b;
    cout << pd[a] - pd[b] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fill_sieve();
  fill_divs();
  int n;
  while (cin >> n) solve(n);
  return 0;
}
