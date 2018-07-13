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
  string line;
  cin >> line;

  string ans;
  for (int i = 0; i < n;) {
    if (i + 3 <= n) {
      string pref = line.substr(i, 3);
      if (pref == "ogo") {
        ans += "***";
        i += 3;
        while (i + 2 <= n && line.substr(i, 2) == "go") {
          i += 2;
        }
      } else {
        ans += line[i++];
      }
    } else {
      ans += line[i++];
    }
  }

  cout << ans << endl;

  return 0;
}
