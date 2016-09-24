#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int MN = 1e5 + 100;

int a[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    int best = 0, id = -1;
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
      if (a[i] > best) {
        best = a[i];
        id = i;
      }
    }
    int ok = true;
    if (best > n) ok = false;
    if (id == 0) {
      ok &= (a[id + 1] == a[id] - 1) ||  (a[id + 1] == a[id] - 2);
    } else if (id == (m - 1)) {
      ok &= (a[id - 1] == a[id] - 1) ||  (a[id - 1] == a[id] - 2);
    } else {
      int t = false;
      t |= (a[id + 1] == a[id] - 1) &&  (a[id - 1] == a[id] - 2);
      t |= (a[id - 1] == a[id] - 1) && (a[id + 1] == a[id] - 2);
      ok &= t;
    }
    if (ok) {
      for (int i = id - 1; i > 0; --i)
        ok &= (a[i - 1] == a[i] - 1) ||  (a[i - 1] == a[i] - 2);
      for (int i = id + 1; i + 1 < m; ++i)
        ok &= (a[i + 1] == a[i] - 1) ||  (a[i + 1] == a[i] - 2);
    }
    puts(ok ? "S" : "N");
  }
  return 0;
}
