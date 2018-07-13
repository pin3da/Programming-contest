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

  string line;
  cin >> line;
  vector<int> upper(line.size()), lower(line.size());

  int n = line.size();
  for (int i = 0; i < n; i++) {
    upper[i] = islower(line[i]) != 0;
    if (i) upper[i] += upper[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    lower[i] = isupper(line[i]) != 0;
    if (i + 1 < n) lower[i] += lower[i + 1];
  }

  int best = min(lower[0], upper[n - 1]);
  for (int i = 0; i < n - 1; i++) {
    int cur = upper[i] + lower[i + 1];
    best = min(best, cur);
  }
  cout << best << endl;

  return 0;
}
