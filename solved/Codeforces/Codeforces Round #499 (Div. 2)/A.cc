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

  int n, k;
  cin >> n >> k;
  vector<int> frec(30);
  for (int i = 0; i < n; i++) {
    char t; cin >> t;
    frec[t - 'a']++;
  }

  int cost = 0;
  for (int i = 0; i < 30 && k > 0; i++) {
    if (frec[i]) {
      cost += (i + 1);
      k--;
      i++;
    }
  }

  if (k == 0) cout << cost << endl;
  else cout << - 1 << endl;

  return 0;
}
