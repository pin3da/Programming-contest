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


long long test(long long x, long long n, long long k) {
  long long num = n / x;
  long long times = (num + k - 1) / k;
  return times;
}

long long find_x(long long target, long long n, long long k) {
  long long lo = 1, hi = 1e18;
  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    if (test(mid, n, k) >= target) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  assert(test(lo, n, k) == target);
  return lo;
}

void solve() {
  long long n, k, M, D;
  read(n, k, M, D);

  long long best = 0;

  for (long long v = 1; v <= D; v++) {
    long long x = min(M, find_x(v, n, k));
    best = max(best, x * test(x, n, k));
  }
  cout << best << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

