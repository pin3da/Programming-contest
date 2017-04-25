// http://codeforces.com/contest/671/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, k;
  while (cin >> n >> k) {
    vector<long long> a(n);
    long long total = 0;
    for (auto &i : a) {
      cin >> i;
      total += i;
    }
    sort(a.begin(), a.end());
    long long lo = 0, hi = (total / n);
    while (lo < hi) {
      long long mid = (lo + hi + 1) >> 1;
      long long need = 0;
      for (int i = 0; i < n; ++i) {
        need += max(0LL, mid - a[i]);
      }
      if (need > k)
        hi = mid - 1;
      else
        lo = mid;
    }

    long long tmp1 = lo;

    lo = (total + n - 1) / n, hi = total;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      long long need = 0;
      for (int i = 0; i < n; ++i) {
        need += max(0LL, a[i] - mid);
      }
      if (need > k)
        lo = mid + 1;
      else
        hi = mid;
    }
    cout << llabs(lo - tmp1) << endl;
  }
  return 0;
}
