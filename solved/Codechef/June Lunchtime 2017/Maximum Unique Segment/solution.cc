#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  vector<long long> a(n), w(n);
  for (auto &i : a) cin >> i;
  for (auto &i : w) cin >> i;


  set<long long> seen;
  int i = 0, j = 0;
  long long sum = 0, best = 0;
  while (j < n) {
    while (j < n && seen.count(a[j]) == 0) {
      seen.insert(a[j]);
      sum += w[j];
      best = max(best, sum);
      j++;
    }
    if (i < j) {
      seen.erase(a[i]);
      sum -= w[i];
      ++i;
    }
  }
  cout << best << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
