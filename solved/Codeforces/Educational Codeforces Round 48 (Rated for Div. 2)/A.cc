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
  long long m; cin >> m;
  long long acc = 0, last = 0;
  for (int i = 0; i < n; i++) {
    long long tmp; cin >> tmp;
    acc += tmp;
    cout << (acc / m) - last << " ";
    last = acc / m;
  }

  cout << endl;
  return 0;
}
