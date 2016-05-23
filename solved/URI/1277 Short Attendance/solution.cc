#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<string> a(n);
    vector<double> p(n);
    int first = true;
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; ++i) {
      string line; cin >> line;
      int cur = 0, tot = 0;
      for (auto &t : line) {
        if (t == 'P') cur++;
        if (t != 'M') tot++;
      }
      if (cur * 4 < 3 * tot) {
        if (!first) cout << ' ';
        cout << a[i];
        first = false;
      }
    }
    cout << endl;
  }
  return 0;
}
