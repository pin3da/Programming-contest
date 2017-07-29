#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool take(multiset<long long> &a, int k, long long c) {
  if (a.size() == 0) return false;
  long long cur = *(a.begin());
  a.erase(cur);
  int taken = 1;
  while (a.size() && taken < k) {
    auto next = a.lower_bound(cur * c);
    if (next == a.end()) return false;
    cur = *next;
    a.erase(cur);
    taken++;
  }
  return true;
}

void solve() {
  long long n, k, c;
  cin >> n >> k >> c;
  multiset<long long> a;
  for (int i = 0; i < n; i++) {
    long long t; cin >> t;
    a.insert(t);
  }
  int ans = 0;
  while (take(a, k, c)) ans++;
  cout << ans << endl;
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
