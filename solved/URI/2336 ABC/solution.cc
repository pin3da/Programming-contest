#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  string line;
  const long long mod = 1e9 + 7;
  while (cin >> line) {
    long long ans = 0;
    for (auto c : line) {
      ans = (ans * 26) % mod;
      ans = (ans + (c - 'A')) % mod;
    }
    cout << ans << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  solve();
  return 0;
}

