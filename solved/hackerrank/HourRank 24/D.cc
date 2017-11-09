#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


long long count(vector<long long> &a, vector<long long> &b,
                int x, long long val) {

}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m, x;
  long long k;
  cin >> n >> m >> x >> k;
  vector<long long> ans;
  vector<long long> a(n), b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  /*
  for (int i = 0; i < min(n, m - x); i++) {
    for (int j = i + x; j < m; j++)
      ans.push_back(a[i] * b[j]);
  }
  sort(ans.begin(), ans.end());
  cout << ans[k - 1] << endl;
  */

  long long lo = -1e11, hi = 1e11;

  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (count(a, b, x, mid) < k) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  cout << lo << endl;
  return 0;
}
