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

  int n, m;
  cin >> n >> m;
  set<int> a, b;
  while (n--) {int t; cin >> t; a.insert(t);}
  while (m--) {int t; cin >> t; b.insert(t);}

  for (int i = 1; i < 10; i++) {
    if (a.count(i) && b.count(i)) {
      cout << i << endl;
      return 0;
    }
  }

  for (int i = 10; i < 100; i++) {
    int x = i / 10, y = i % 10;
    if ((a.count(x) || a.count(y)) && (b.count(x) || b.count(y))) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
