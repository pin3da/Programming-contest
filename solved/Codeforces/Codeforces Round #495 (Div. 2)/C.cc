#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n; cin >> n;
  vector<int> a(n);
  set<int> seen;
  vector<int> le;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (seen.count(a[i]) == 0) {
      seen.insert(a[i]);
      le.push_back(i);
    }
  }

  seen.clear();
  long long ans = 0;
  int right = le.size() - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (seen.count(a[i]) == 0) {
      seen.insert(a[i]);
      while (right >= 0 && le[right] >= i) {
        right--;
      }
      ans += (right + 1);
    }
  }
  cout << ans << endl;

  return 0;
}
