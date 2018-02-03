#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif

const int MN = 1000000 + 10;

long long primes[MN];
bool sieve[MN];
int phi[MN];
int num_p;

void fill_sieve() {
  num_p = 0;
  sieve[0] = sieve[1] = true;

  for (long long i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      primes[num_p++] = i;
      for (long long j = i * i; j < MN; j += i)
        sieve[j] = true;
    }
  }

  for (int i = 1; i < MN; i++)
    phi[i] = i;

  for (int i = 1; i < MN; i++)
    if (!sieve[i]) // is prime
      for (int j = i; j < MN; j += i)
        phi[j] -= phi[j] / i;

}

vector<pair<int, int>> factor(int n) {
  vector<pair<int, int>> ans;
  if (n == 0) return ans;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      int expo = 0;
      while ((n % primes[i]) == 0) {
        expo++;
        n /= primes[i];
      }
      ans.emplace_back(primes[i], expo);
    }
  }

  if (n > 1) {
    ans.emplace_back(n, 1);
  }
  return ans;
}

int num_cop(vector<long long> &fact, long long x) {

  long long total = x;

  int top = 1 << (fact.size());

  for (int i = 1; i < top; i++) {
    int par = __builtin_popcount(i);
    int sig = (par & 1) ? -1 : 1;

    long long cur = 1;
    for (int k = 0; k < int(fact.size()); k++) {
      if ((i >> k) & 1)
        cur *= fact[k];
    }
    total += sig * (x / cur);
  }

  return total;
}

void solve() {
  int x, p, k;
  cin >> x >> p >> k;

  auto tmp = factor(p);
  vector<long long> fact;
  for (auto it : tmp) fact.emplace_back(it.first);

  int base = num_cop(fact, x);

  long long lo = base, hi = 1e8;

  k += base;

  while (lo < hi) {
    long long mid = (lo + hi) >> 1;

    if (num_cop(fact, mid) < k) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  cout << lo << endl;

}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  fill_sieve();

  int t; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
