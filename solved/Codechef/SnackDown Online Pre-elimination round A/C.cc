#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void solve() {
  int n; cin >> n;
  vector<int> all(n + 2);
  long long total = 0;
  for (int i = 1; i < n + 1; ++i) {
    cin >> all[i];
    total += all[i];
  }
  vector<int> left(n + 2), right(n + 2);
  for (int i = 1; i < n + 1; ++i) {
    left[i] = min(left[i - 1] + 1, all[i]);
  }
  for (int i = n; i > 0; --i)
    right[i] = min(right[i + 1] + 1, all[i]);

  long long best = 0;
  for (int i = 1; i < n + 1; ++i)
    best = max<long long>(best, min(right[i], left[i]));

  cout << total - ((best * (best + 1)) / 2)  - (best * (best - 1) / 2) << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--)
    solve();

  return 0;
}
