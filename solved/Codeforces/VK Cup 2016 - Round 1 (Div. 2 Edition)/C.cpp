// http://codeforces.com/contest/658/problem/C

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, h, d;
  while (cin >> n >> d >> h) {
    if ((d > 2 * h) ||  (d < h) || (n > 2 && d == 1 && h == 1)) {
      cout << -1 << endl;
      continue;
    }
    int last = 0;
    for (int i = 0; i < h; ++i) {
      cout << i + 1 << ' ' << i + 2 << endl;
      last = i + 2;
    }
    d -= h;
    if (d) {
      cout << 1 << ' ' << last + 1 << endl;
      last++; d--;
      for (int i = 0; i < d; ++i) {
        cout << last << ' ' << last + 1 << endl;
        last++;
      }
      last++;
      while (last <= n) {
        cout << 1 << ' ' << last << endl;
        last++;
      }
    } else {
      int t = last - 1;
      last++;
      while (last <= n) {
        cout << t << ' ' << last << endl;
        last++;
      }
    }
  }
  return 0;
}
