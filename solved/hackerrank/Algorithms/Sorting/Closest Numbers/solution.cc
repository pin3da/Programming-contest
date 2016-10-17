#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int MN = 200000 + 100;
int a[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a + n);
    int best = 1e9;
    for (int i = 0; i + 1 < n; ++i)
      best = min(best, a[i + 1] - a[i]);
    int f = false;
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i + 1] - a[i] == best) {
        if (f) cout << ' ';
        f = true;
        cout << a[i] << ' ' << a[i + 1];
      }
    }
    cout << endl;
  }

  return 0;
}
