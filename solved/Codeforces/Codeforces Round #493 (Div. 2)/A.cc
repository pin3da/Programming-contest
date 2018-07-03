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
  vector<pair<int, int>> data(n);

  for (int i = 0; i < n; i++) {
    cin >> data[i].first;
    data[i].second = i + 1;
  }

  sort(data.begin(), data.end());
  if (n == 1 || (n == 2 && (data[0].first == data[1].first))) {
    cout << -1 << endl;
  } else {
    cout << n - 1 << endl;
    for (int i = 1; i < n; i++) cout << data[i].second << " ";
    cout << endl;
  }

  return 0;
}
