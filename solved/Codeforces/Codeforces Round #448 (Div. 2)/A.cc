#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  int best = 500;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = i; j < n; j++) {
      cur += a[j];
      int tmp = 360 - cur;
      best = min(best, abs(tmp - cur));
    }
  }
  cout << best << endl;

  return 0;
}
