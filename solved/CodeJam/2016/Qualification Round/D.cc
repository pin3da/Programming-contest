#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

using namespace std;

void solve() {
  long long k, s, c;
  cin >> k >> c >> s;
  for (int i = 1; i <= k; ++i)
    cout << ' ' << i;
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << (i + 1) << ":";
    solve();
  }

  return 0;
}
