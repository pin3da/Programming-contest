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

vector<long long> factors(long long n) {
  vector<long long> ans;
  for (int i = 0; i < num_p && primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      ans.push_back(primes[i]);
      while ((n % primes[i]) == 0) n /= primes[i];
    }
  }
  if (n > 1)
    ans.push_back(n);
  return ans;
}

long long fun(long long n, long long p) {
  long long k = n / p;
  return p * (k) * (k + 1) >> 1;
}

long long get(vector<long long> &f, long long n) {
  int t = f.size();
  long long total = 0;
  for (int mask = 1; mask < (1 << t); ++mask) {
    int sig = (!(__builtin_popcount(mask) & 1)) ? -1 : 1;
    long long cur = 1;
    for (int j = 0; j < f.size(); ++j) {
      if ((mask >> j) & 1)
        cur *= f[j];
    }
    total = (total + sig * fun(n, cur));
  }
  return total;
}

void solve(long long n) {
  cout << totient(n) << " ";
  vector<long long> fact = factors(n);
  long long num = ((n * (n + 1)) >> 1);
  num = num - get(fact, n);
  cout << double(num) / n << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  fill_sieve();
  cout << fixed << setprecision(4);

  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    long long tmp;
    cin >> tmp;
    solve(tmp);
  }

  return 0;
}
