#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


int long_increasing(vector<int> &a) {
  int n = a.size();
  int best = 1;
  int i = 0, j = 1;
  if (a.size() == 1) return 1;
  while (j < n && i < n) {
    if ((a[j - 1] - a[j]) >= 0) {
      j++;
      best = max(best, j - i);
    } else {
      i++;
    }

    while (j <= i) j++;
  }
  return best;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> all(n);
  for (auto &i : all) cin >> i;

  int ans1 = long_increasing(all);
  reverse(all.begin(), all.end());
  int ans2 = long_increasing(all);
  cout << max(ans1, ans2) << endl;

  return 0;
}
