#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<int> a(5);
  for (auto &i : a)  cin >> i;
  sort(a.begin(), a.end());
  int total = accumulate(a.begin(), a.end(), 0);
  int best = total;
  for (int i = 0; i < 5; ++i) {
    if (i + 2 < 5) {
      if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
        best = min(best, total - 3 * a[i]);
    }
    if (i + 1 < 5) {
      if (a[i] == a[i + 1])
        best = min(best, total - 2 * a[i]);
    }
  }
  cout << best << endl;

  return 0;
}
