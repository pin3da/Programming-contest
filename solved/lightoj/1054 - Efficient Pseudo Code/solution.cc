using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const long long mod = 1000000007;
const long long MN  = 65536 + 10;


vector<pair<int, int> > factorize(vector<int> &primes, long long n) {
  vector<pair<int, int> > ans;
  for (long long i = 0, p = primes[i]; p * p <= n; p = primes[++i]) {
    int exp = 0;
    while (n % p == 0) {
      exp++;
      n /= p;
    }
    if (exp > 0)
      ans.push_back(make_pair(p, exp));
  }
  if (n > 1)
    ans.push_back(make_pair(n, 1));
  return ans;
}

long long mod_pow(long long a, long long e, long long mod) {
  long long ans = 1;
  long long base = a;
  while (e > 0) {
    if (e & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    e >>= 1;
  }
  return ans;
}

void solve(vector<int> &primes) {
  long long n, m;
  cin >> n >> m;
  vector<pair<int, int> > fact = factorize(primes, n);
  long long ans = 1;
  for (int i = 0; i < fact.size(); ++i) {
    long long p = fact[i].first, e = fact[i].second;
    ans = (ans * (mod_pow(p, e * m + 1LL, mod) - 1LL + mod)) % mod;
    ans = (ans * mod_pow(p - 1LL, mod - 2, mod)) % mod;
  }
  printf("%lld\n", ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> primes;
  vector<bool> sieve(MN, true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i < MN; ++i) {
    if (sieve[i]) {
      primes.push_back(i);
      long long j = i; j *= i;
      while (j < MN) {
        sieve[j] = false;
        j += i;
      }
    }
  }

  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve(primes);
  }
  return 0;
}
