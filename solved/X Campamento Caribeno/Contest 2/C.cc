#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

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

void gen_divisors(vector<pair<int, int>> &f, size_t id,
    long long cur, vector<long long> &divs) {

  if (id == f.size()) {
    divs.push_back(cur);
    return;
  }

  for (int i = 0; i <= f[id].second; i++) {
    gen_divisors(f, id + 1, cur, divs);
    cur *= f[id].first;
  }
}

const long long mod = 1000000000 + 7;

long long mult(long long a, long long b) {
  if (a >= mod) assert(false);
  return (a * b) % mod;
}

long long add(long long a, long long b) {
  return (a + b) % mod;
}

long long mod_pow(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = mult(ans, b);
    b = mult(b, b);
    e >>= 1;
    if (ans >= mod) assert(false);
  }
  return ans;
}

long long mod_inv(long long a) {
  return mod_pow(a, mod - 2);
}

void solve() {
  long long p, n;
  cin >> p >> n;
  vector<pair<int, int>> f = factor(p - 1);
  vector<long long> divs;
  gen_divisors(f, 0, 1, divs);
  long long times = divs.size();
  for (int i = 0; i < times; i++)
    divs.push_back(divs[i] * p);


  long long a0 = p - 1;
  long long total = 0;
  for (auto d : divs) {
    long long a1 = d + p - 1;
    long long a2 = ((p - 1) * p) / d + p;

    if (n == 0) {
      total = add(total, a0);
    } else if (n == 1) {
      total = add(total, a1);
    } else {
      a2 %= mod;
      total = add(total, mult(a2, mod_pow(p, n - 2)));
    }
  }

  cout << 2 * times << " " << total << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  fill_sieve();
  solve();
  return 0;
}

