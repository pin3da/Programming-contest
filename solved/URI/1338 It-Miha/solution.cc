#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long MVAL = 20000000000LL;
const int MN = 200000 + 100;

long long primes[MN];
int num_pri;
bool sieve[MN];

long long fun(int id, long long cur, long long k) {
  if (id >= num_pri) return 0;
  long long sq = primes[id] * primes[id];
  if (cur <= k / sq) {
    long long ans = k / (cur * sq);
    ans += fun(id + 1, cur, k);
    ans -= fun(id + 1, cur * sq, k);
    return ans;
  }
  return 0;
}

bool test(long long k, long long n) {
  return (k - fun(0, 1, k)) >= n;
}

void solve() {
  long long n; cin >> n;
  long long lo = 0, hi = MVAL << 1 | 1;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (test(mid, n)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  sieve[0] = 1;
  sieve[1] = 1;

  num_pri = 0;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      primes[num_pri++] = i;
      for (int j = i + i; j < MN; j += i) sieve[j] = 1;
    }
  }
  int n; cin >> n;
  while (n--) solve();
  return 0;
}
