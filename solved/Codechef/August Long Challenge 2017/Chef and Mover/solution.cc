#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool fix(vector<long long> &a, long long target, long long &cost) {
  long long acc = accumulate(a.begin(), a.end(), 0LL);
  if (acc % target) return false;
  acc = 0;
  long long ans = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    acc += a[i] - target;
    ans += abs(acc);
  }
  cost += ans;
  return true;
}

void solve() {
  int n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  long long total = accumulate(a.begin(), a.end(), 0LL);
  if (total % n) {
    cout << -1 << endl;
    return;
  }
  long long target = total / n;
  vector<vector<long long>> bucket(d);
  for (int i = 0; i < n; i++) {
    bucket[i % d].push_back(a[i]);
  }

  long long ans = 0;
  for (int i = 0; i < d; i++) {
    if (!fix(bucket[i], target, ans)) {
      cout << -1 << endl;
      return;
    }
  }

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
