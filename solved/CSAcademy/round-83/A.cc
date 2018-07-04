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

  string pattern;
  cin >> pattern;

  long long ans = 1;

  int n = pattern.size();
  for (int i = 0; i < n; i++) {
    int val = pattern[i] == 'd' ? 10 : 26;
    if (i > 0 && (pattern[i] == pattern[i - 1])) val--;
    ans *= val;
  }
  cout << ans << endl;
  return 0;
}
