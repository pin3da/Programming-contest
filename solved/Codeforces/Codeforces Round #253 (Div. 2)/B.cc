#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

bool cmp(string &s, int a, int b) {
  if (a >= int(s.size()) || b >= int(s.size())) return true;
  return s[a] == s[b];
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  string s;
  cin >> s;
  int k; cin >> k;

  int total = (s.size() + k) / 2;

  int ans = 0;
  for (int len = 1; len <= total; len++) {
    for (int i = 0; i + len + len <= int(s.size() + k); i++) {
      int ok = true;
      for (int j = 0; j < len; j++) {
        ok &= (cmp(s, i + j, i + len + j));
      }
      if (ok) ans = len;
    }
  }
  cout << ans * 2 << endl;
  return 0;
}
