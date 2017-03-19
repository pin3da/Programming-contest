#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

long long get_pos(vector<long long> &a, long long sum) {
  long long ans = 0;

  int n = a.size();
  int i = 0, j = n - 1;
  while (i < j) {
    while (i < j && a[i] + a[j] > sum)
      --j;
    if (i >= j) break;
    ans += (j - i);
    ++i;
  }

  return ans + 1;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());

  long long lo = 0, hi = 1e10;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (get_pos(a, mid) < k)
      lo = mid + 1;
    else
      hi = mid;
  }
  cout << lo << endl;

  return 0;
}
