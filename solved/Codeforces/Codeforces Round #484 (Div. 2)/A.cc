#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int len; cin >> len;
  string line; cin >> line;

  if (len == 1) {
    puts(line == "1" ? "Yes" : "No");
    return;
  }

  int ok = (line.find("11") == string::npos);

  for (int i = 0; i < len; i++) {
    if (line[i] == '0') {
      int can = 1;
      if (i > 0) {
        can &= line[i - 1] != '1';
      }
      if (i + 1 < len) {
        can &= line[i + 1] != '1';
      }
      if (can)
        ok = false;
    }
  }

  puts(ok ? "Yes" : "No");

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  //int tc; cin >> tc;
  //while (tc--)
    solve();
  return 0;
}

