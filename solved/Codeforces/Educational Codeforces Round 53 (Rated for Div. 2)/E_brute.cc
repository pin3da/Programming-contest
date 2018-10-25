#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const long long mod = 998244353;

int f(string s) {
  set<char> a;
  for (auto c : s) a.insert(c);
  return a.size();
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  long long l, r, k;
  cin >> l >> r >> k;
  long long ans = 0;
  for (auto i = l; i <= r; i++) {
    if (f(to_string(i)) <= k) {
      ans = (ans + i) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
