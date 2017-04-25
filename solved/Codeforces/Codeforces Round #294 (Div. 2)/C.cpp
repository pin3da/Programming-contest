// http://codeforces.com/contest/519/problem/C

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() { ___

  int n,m;
  while (cin >> n >> m ) {
    int best = 0;
    for (int i = 0; i <= n + m; ++i) {
      int b1 = n  - 2 * i;
      int b2 = (m - i) / 2;
      if (b1 >=0  and (m - i) >= 0) {
        best = max(best, i + min(b1, b2));
      }
    }
    cout << best << endl;

  }
  return 0;
}