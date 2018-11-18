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
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  int total = n;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] >= a[i + 1]) total--;
  }
  cout << total << endl;
  return 0;
}
