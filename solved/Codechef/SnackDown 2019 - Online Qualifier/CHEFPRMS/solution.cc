#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

vector<int> GenPrimes(const int N) {
  vector<bool> sieve(N, true);
  vector<int> primes;
  for (int i = 2; i < N; i++) {
    if (sieve[i]) {
      primes.push_back(i);
      for (int j = i + i; j < N; j += i) sieve[j] = false;
    }
  }
  return primes;
}

vector<int> GenSemiPrimes(vector<int> &primes) {
  vector<int> semi;
  const int n = primes.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      semi.push_back(primes[i] * primes[j]);
    }
  }
  return semi;
}

bool solve(vector<int> &semi) {
  int n;
  cin >> n;
  for (auto a : semi)
    for (auto b : semi)
      if (a + b == n) return true;

  return false;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  auto primes = GenPrimes(222);
  auto semi = GenSemiPrimes(primes);
  int t;
  cin >> t;
  while (t--) {
    puts(solve(semi) ? "YES" : "NO");
  }

  return 0;
}
