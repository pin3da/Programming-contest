#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

bool check(vector<long long> &v, long long s, long long t) {
  long long total = 0;
  for (auto i : v) {
    if (i < t) return false;
    total += i - t;
  }
  return total >= s;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  long long n, s;
  cin >> n >> s;
  vector<long long> v(n);
  for (auto &it : v) cin >> it;

  long long total = accumulate(v.begin(), v.end(), 0LL);

  if (total < s) {
    cout << -1 << endl;
  } else {
    long long lo = 0, hi = 1e9 + 1;
    while (lo < hi) {
      long long mid = (lo + hi + 1) >> 1;
      if (check(v, s, mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << lo << endl;
  }

  return 0;
}
