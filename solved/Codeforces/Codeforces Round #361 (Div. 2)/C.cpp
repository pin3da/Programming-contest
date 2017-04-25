// http://codeforces.com/contest/689/problem/C

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const long long MN = 1000000LL * 1000000LL * 1000LL * 8LL * 100LL;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  deque<long long> p;
  for (long long i = 2; i * i * i <= MN; ++i) {
    p.emplace_back(i * i * i);
  }

  long long n;
  while (cin >> n) {
    long long lo = 1, hi = MN;
    while (lo < hi) {
      long long mid = (lo + hi + 1) >> 1;
      long long ways = 0;
      for (auto &i : p)
        ways += mid / i;
      if (ways < n)
        lo = mid;
      else
        hi = mid - 1;
    }

    lo++;
    long long ways = 0;
    for (auto &i : p)
      ways += lo / i;
    if (ways == n)
      cout << lo << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}
