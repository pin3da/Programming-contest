#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

long long get_divs(long long lo, long long hi, long long x) {
  if (hi < lo) return -1;
  return (hi / x) - ((lo - 1) / x);
}

long long find_min(long long start, long long x, long long k) {
  long long lo = start;
  long long hi = 1e9;
  if (get_divs(start, hi, x) < k) return -1;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (get_divs(start, mid, x) < k) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  if (get_divs(start, lo, x) != k)
    return -1;
  return lo;
}


long long find_max(long long start, long long x, long long k) {
  long long lo = start;
  long long hi = 1e9;
  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    if (get_divs(start, mid, x) > k) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  if (get_divs(start, lo, x) != k)
    return -1;
  return lo;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n, x, k;
  cin >> n >> x >> k;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;

  sort(a.begin(), a.end());

  long long ans = 0;
  n = a.size();
  for (int i = 0; i < n; i++) {
    long long lo = find_min(a[i], x, k);
    long long hi = find_max(a[i], x, k);
    if (lo == -1 || hi == -1) continue;
    auto first = lower_bound(a.begin() + i, a.end(), lo);
    auto second = upper_bound(a.begin() + i, a.end(), hi);
    if (second == a.begin()) continue;
    second--;

    // debug(first - a.begin());
    // debug(second - a.begin());

    if (first <= second) {
      ans += (second - first + 1);
    }

    // debug(ans);

    if (first == (a.begin() + i)) {
      auto equal = upper_bound(a.begin() + i, a.end(), a[i]);
      equal--;
      if (first < equal) {
        ans += (equal - first);
      }
    }

  }

  cout << ans << endl;


  return 0;
}
