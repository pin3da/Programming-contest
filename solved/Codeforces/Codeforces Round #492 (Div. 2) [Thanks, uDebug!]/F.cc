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
  cout << fixed << setprecision(8);

  int n, r;
  cin >> n >> r;
  debug(1 << n);
  vector<double> val(1 << n);
  double den = 1 << n;
  double total = 0;
  for (auto &it : val) {
    cin >> it;
    total += it;
  }

  cout << total / den << endl;

  while (r--) {
    int id;
    double t;
    cin >> id >> t;
    total -= val[id];
    val[id] = t;
    total += val[id];
    cout << total / den << endl;
  }

  return 0;
}
