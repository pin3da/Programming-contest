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

const int MN = 1000012;
int LCM_ORI[MN];
int LCM_TAR[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill_sieve();

  int n, top;
  cin >> n >> top;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    vector<pair<long long, int>> f = factor(t);
    for (int j = 0; j < f.size(); j++) {
      int pri = f[j].first;
      int val = f[j].second;
      LCM_ORI[pri] = max(LCM_ORI[pri], val);
    }
  }
  long long lcm = 1;
  for (int j = 0; j < MN; j++) {
    for (int k = 0; k < LCM_ORI[j]; k++)
      lcm *= j;
  }
  long long extra = top / lcm;
  for (int i = 0; i < MN; i++)
    LCM_TAR[i] = LCM_ORI[i];

  vector<pair<long long, int>> f = factor(extra);
  for (auto it: f) {
    LCM_TAR[it.first] += it.second;
  }

  long long ans = 1;
  for (int i = 0; i < MN; i++) {
    if (LCM_TAR[i] > LCM_ORI[i]) {
      for (int j = 0; j < LCM_TAR[i]; j++)
        ans *= i;
    }
  }
  cout << ans << endl;
  return 0;
}
