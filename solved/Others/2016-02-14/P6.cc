#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, p;
  int t, b;
  while (cin >> n >> p && (n + p)) {
    vector<stack<int>> a(p);
    int x, y;
    for (int i = 0; i < p; ++i) {
      cin >> t;
      for (int j = 0; j < t; ++j) {
        cin >> b;
        a[i].push(b);
        if (b == 1)
          x = i, y = j;
      }
    }

    int right = 0, left = 0;
    for (int i = x + 1; i < p; ++i) {
      if (a[i].size() > y) {
        right += a[i].size() - y;
      } else
        break;
    }

    for (int i = x - 1; i >= 0; --i) {
      if (a[i].size() > y) {
        left += a[i].size() - y;
      } else
        break;
    }

    cout << min(left, right) + a[x].size() - y - 1 << endl;
  }
  return 0;
}
