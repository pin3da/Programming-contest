#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int h, w; cin >> h >> w;
  vector<int> a(h), b(h);
  int best = 1e7;
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;

  for (int i = 0; i < h; ++i)
    best = min(best, w - a[i] - b[i]);

  double ans = best * 0.5;
  cout << ans << endl;

  return 0;
}
