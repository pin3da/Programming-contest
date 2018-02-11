#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);   debug_out(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#define endl '\n'
#endif


int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  map<string, int> values;
  values["red"] = 1; values["yellow"] = 2; values["green"] = 3; values["brown"] = 4; values["blue"] = 5; values["pink"] = 6; values["black"] = 7;
  int n;
  string s;
  while (cin >> n) {
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
      cin >> s;
      data[i] = values[s];
    }
    sort(data.begin(), data.end());
    if (data[0] == data[n - 1] && data[0] == 1) {
      cout << 1 << endl;
    } else {
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if (data[i] == 1) ans += 1 + data[n - 1];
        else ans += data[i];
      }
      cout << ans << endl;
    }
  }

  return 0;
}
