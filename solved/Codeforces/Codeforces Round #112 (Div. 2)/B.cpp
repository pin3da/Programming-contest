// http://codeforces.com/contest/165/problem/B

using namespace std;
#include <bits/stdc++.h>

long long sim(long long v, long long k) {
  long long ans = v;
  long long base = k;
  while (base <= v) {
    ans += v / base;
    base *= k;
  }
  return ans;
}

int main() {
  long long n, k;
  while (cin >> n >> k) {
    long long lo = 0, hi = n;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      if (sim(mid, k) >= n)
        hi = mid;
      else
        lo = mid + 1;
    }
    cout << lo << endl;
  }
  return 0;
}
