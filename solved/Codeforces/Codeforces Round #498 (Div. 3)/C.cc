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
  vector<long long> data(n), pref(n);
  for (int i = 0; i < n; i++) {
    cin >> data[i];
    pref[i] = data[i];
    if (i) pref[i] += pref[i - 1];
  }
  long long best = 0, acc = 0;
  for (int i = n - 1; i >= 0; i--) {
    acc += data[i];
    auto it = lower_bound(pref.begin(), pref.end(), acc);
    if (it == pref.end() || (*it) != acc) continue;
    if ((it - pref.begin()) < i) best = acc;
    else break;
  }
  cout << best << endl;

  return 0;
}
