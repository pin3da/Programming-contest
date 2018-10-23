#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }

  vector<long long> cand;
  int i = 0;
  int ok = true;
  while (i < n && ok) {
    while (a[i] < 0) i++;
    int j = i + 1;
    while (j < n && a[j] < 0) j++;
    if (j < n) {
      if (a[i] <= a[j]) {
        long long tmp = j - i;
        tmp = tmp - (a[j] - a[i]);
        if (tmp < 0) ok = false;
        cand.push_back(tmp);
      } else {  // a[j] > a[j]
        long long tmp = j - i; // 1
        if (tmp <= a[j]) ok = false;
        tmp = tmp + a[i] - a[j];
        if (tmp < 0) ok = false;
        cand.push_back(tmp);
      }
    }
    i = j;
  }

  if (!ok) {
    cout << "impossible" << endl;
  } else {
    long long ans = 0;
    for (auto it : cand) if (it) ans = __gcd(ans, it);
    if (ans == 0) {
      cout << "inf" << endl;
    } else if (ans == 1) {
      int tmp = true;
      for (auto it : a) {
        if (it < 0) continue;
        tmp &= (it == 0);
      }
      if (tmp) cout << 1 << endl;
      else cout << "impossible" << endl;
    } else {
      cout << ans << endl;
    }
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
