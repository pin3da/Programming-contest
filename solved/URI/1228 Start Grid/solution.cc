#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    vector<int> b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x = i;
      for (int j = 0; j < n; ++j) if (b[j] == a[i]) x = j;
      for (int j = i + 1; j < n; ++j) {
        for (int k = 0; k < x; ++k) {
          if (a[j] == b[k]) ans++;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
