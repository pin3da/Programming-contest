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
  vector<int> a(n);
  int pos = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == m) pos = i;
  }

  map<int, int> frec;
  int acc = 0;
  for (int i = pos; i >= 0; i--) {
    int delta = 0;
    if (a[i] < m) delta = -1;
    else if (a[i] > m) delta = 1;

    acc += delta;
    frec[acc]++;
  }

  long long ans = 0;

  acc = 0;
  for (int i = pos; i < n; i++) {
    int delta = 0;
    if (a[i] < m) delta = -1;
    else if (a[i] > m) delta = 1;

    acc -= delta;

    ans += frec[acc] + frec[acc + 1];
  }
  cout << ans << endl;
  return 0;
}
