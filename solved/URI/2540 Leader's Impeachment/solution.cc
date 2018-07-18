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

  int n;
  while (cin >> n) {
    vector<int> val(2);
    for (int i = 0; i < n; i++) {
      int t; cin >> t;
      val[t]++;
    }
    if (val[1] * 3 >= n * 2) {
      cout << "impeachment" << endl;
    } else {
      cout << "acusacao arquivada" << endl;
    }
  }

  return 0;
}
