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
  long long swap, toggle;
  cin >> n >> swap >> toggle;
  vector<int> data;
  int prev = - 1;
  for (int i = 0; i < n; i++) {
    char tmp; cin >> tmp;
    int t = tmp - '0';
    if (t != prev) data.push_back(t);
    prev = t;
  }

  vector<long long> frec(2);
  for (auto it : data) frec[it == 1]++;

  if (toggle <= swap) {
    cout << frec[0] * toggle << endl;
  } else {
    if (frec[0])
      cout << swap * (frec[0] - 1) + toggle << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
