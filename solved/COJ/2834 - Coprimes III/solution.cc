#include<bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x << " = " << x << endl
using namespace std;


const int MX = 100000 + 100;
const long long mod = 1000000007;
vector<long long> primes;
bool check[MX];

void genP() {
  primes.push_back(2);
  for(int i = 3; i < MX; i += 2) {
    if(check[i]) continue;
    primes.push_back(i);
    for(int j = i + i; j < MX; j += i) check[j] = true;
  }
}

vector<long long> pdiv(long long n) {
  vector<long long> a;
  for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      a.push_back(primes[i]);
      while ((n % primes[i]) == 0) {
        n /= primes[i];
      }
    }
  }
  if (n > 1)
  a.push_back(n);
  return a;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long n;
  genP();

  while (cin >> n) {
    vector<long long> p = pdiv(n);
    long long total = 0;
    for (int i = 1; i < (1 << p.size()); ++i) {
       int neg = !(__builtin_popcount(i) & 1);
       long long den = 1;
       for (int j = 0; j < p.size(); ++j) {
          if ((i >> j) & 1) den *= p[j];
       }
       long long cur = (n - 1) / den;
       cur = den * (cur * (cur + 1)) / 2;
       cur %= mod;
       if (neg) {
          total = (total + mod - cur) % mod;
       } else {
         total = (total + cur) % mod;
       }
    }
    cout << (total + mod) % mod << endl;
  }
  return 0;
}
