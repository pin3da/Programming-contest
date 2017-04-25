// http://codeforces.com/contest/670/problem/A

#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    int a = 0, b = 5;
    int mmin = 0, mmax = 0;
    for (int i = 0; i < n; ++i) {
      if (a >= 5) mmin++;
      if (b >= 5) mmax++;
      a = (a + 1) % 7;
      b = (b + 1) % 7;
    }
    cout << min(mmin, mmax) << " " << max(mmin, mmax) << endl;
  }

  return 0;
}
