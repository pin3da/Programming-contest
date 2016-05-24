#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> d(n);
    for (auto &i : d) cin >> i;
    vector<int> a(n + n + 1);
    for (int i = 0; i < n; ++i)
      a[i + 1] = a[i] + d[i];
    for (int i = 0; i < n; ++i)
      a[i + n + 1] = a[i + n] + d[i];
    int total = accumulate(d.begin(), d.end(), 0);
    if ((total % 3) == 0) {
      int ans = 0;
      int delta = total / 3;
      for (int i = 0; i < n; ++i) {
        int x1 = a[i] + delta;
        int x2 = x1 + delta;
        if (binary_search(a.begin(), a.end(), x1) && binary_search(a.begin(), a.end(), x2))
          ans++;
      }
      cout << ans / 3 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
