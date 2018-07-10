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

  string a, b;
  cin >> a >> b;

  int len = min(a.size(), b.size());

  int last = 0;
  for (int i = 0; i < len; i++) {
    if (a[a.size() - 1 - i] != b[b.size() - 1 - i]) break;
    last++;
  }

  cout << (a.size() + b.size() - 2 * last) << endl;
  return 0;
}
