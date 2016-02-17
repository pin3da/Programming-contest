#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int k;
  while (cin >> k && k) {
    int n, m;
    cin >> n >> m;
    while (k--) {
      int x, y;
      cin >> x >> y;
      if (x == n || y == m) {
        cout << "divisa" << endl;
      } else {
        if (x > n) {
          if (y > m)
            cout << "NE" << endl;
          else
            cout << "SE" << endl;
        } else {
          if (y > m)
            cout << "NO" << endl;
          else
            cout << "SO" << endl;
        }
      }
    }
  }
  return 0;
}
