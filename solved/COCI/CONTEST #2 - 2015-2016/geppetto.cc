using namespace std;
#include <bits/stdc++.h>

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> r(m);
  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    a--; b--;
    r[i] |= (1 << a) | (1 << b);
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int ok = 1;
    for (int j = 0; j < m && ok; ++j) {
      if ((mask & r[j]) == r[j]) ok = false;
    }
    ans += ok;
  }
  cout << ans << endl;
  return 0;
}
