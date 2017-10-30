#include <bits/stdc++.h>

using namespace std;

const int MP = 1000123;
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

vector<pair<long long, int>> factor(long long n) {
  vector<pair<long long, int>> ans;
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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill_sieve();


  long long n; cin >> n;
  vector<pair<long long, int>> ans = factor(n);
  long long cur = 1;
  for (int i = 0; i < ans.size(); i++) {
    cur *= 2;
  }
  cur -= (ans.size() + 1);
  cout << cur << endl;
  return 0;
}
