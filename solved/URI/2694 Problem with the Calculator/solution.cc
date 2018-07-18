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

  int tc; cin >> tc;
  while (tc--) {
    string line; cin >> line;
    for (auto &it : line)
      if (!isdigit(it))
        it = ' ';
    stringstream ss(line);
    int ans = 0, cur = 0;
    while (ss >> cur) ans += cur;
    cout << ans << endl;
  }
  return 0;
}
