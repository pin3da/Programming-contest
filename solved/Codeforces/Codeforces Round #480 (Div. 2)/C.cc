#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n; cin >> n;
  int k; cin >> k;
  vector<int> color(256, -1);
  vector<int> input(n);
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    input[i] = t;

    if (color[t] == -1) {
      int start = t;
      for (int j = 0; j < k && t - j >= 0; j++) {
        if (color[t - j] != -1) break;
        start = t - j;
      }

      if (start != 0) {
        if (t - color[start - 1] + 1 <= k)
          start = color[start - 1];
      }

      for (int j = 0; j < k && t - j >= 0; j++) {
        if (color[t - j] != -1) break;
        color[t - j] = start;
      }
    }
    cout << color[t] << " ";
  }
  cout << endl;
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

