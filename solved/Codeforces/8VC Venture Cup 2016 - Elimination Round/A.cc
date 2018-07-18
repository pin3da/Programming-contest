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
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    vector<int> d(4);
    for (int j = i; j < n; j++) {
      for (int k = 0; k < 4; k++) {
        if (line[j] == "URDL"[k]) d[k]++;
      }
      if ((d[0] == d[2]) && (d[1] == d[3])) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
