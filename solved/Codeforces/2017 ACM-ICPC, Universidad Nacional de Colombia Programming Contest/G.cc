#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

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

vector<int> factor(int n) {
  vector<int> ans;
  if (n == 0) return ans;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      while ((n % primes[i]) == 0) {
        ans.emplace_back(primes[i]);
        n /= primes[i];
      }
    }
  }

  if (n > 1) {
    ans.emplace_back(n);
  }
  return ans;
}


const long long mod = 1e9 + 7;

long long dp[1111];
long long go(string &s, int id) {
  if ((int)s.size() == id) return 1;

  if (dp[id] != -1) return dp[id];
  long long ans = go(s, id + 1) * (s[id] != '0');
  if ((s[id] != '0') && (id + 1) < (int) s.size()) {
    string next(2, 0);
    next[0] = s[id];
    next[1] = s[id + 1];
    if (stoi(next) < 27) {
      ans = (ans + go(s, id + 2)) % mod;
    }
  }
  return dp[id] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  fill_sieve();

  int n;
  map<int, int> seen;
  while (cin >> n) {
    if (seen.count(n) == 0) {
      vector<int> fac = factor(n);
      string s;
      for (auto i : fac)
        s += to_string(i);
      sort(s.begin(), s.end());
      long long ans = 0;
      do {
        memset(dp, -1, sizeof dp);
        ans = (ans + go(s, 0)) % mod;
      } while (next_permutation(s.begin(), s.end()));
      seen[n] = ans;
    }
    cout << seen[n] << endl;
  }

  return 0;
}
