#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; } template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }


int main() {
#ifndef LOCAL
#define endl '\n'
#define debug(...) //
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

  int tc; cin >> tc;
  while (tc--) {
    string line; cin >> line;
    int ans = 0;
    for (int i = 0; i + 3 < int(line.size()); i++) {
      string tmp = line.substr(i, 4);
      sort(tmp.begin(), tmp.end());
      if (tmp == "cefh") ans++;
    }
    if (ans)
      cout << "lovely " << ans << endl;
    else
      cout << "normal" << endl;
  }
  return 0;
}
