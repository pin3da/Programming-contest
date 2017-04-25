// http://codeforces.com/contest/14/problem/B

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___
  int pos, n;
  cin >> n >> pos;

  int x, y;
  cin >> x >> y;
  int a = min(x, y);
  int b = max(x, y);

  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    a = max(a, min(x, y));
    b = min(b, max(x, y));
  }
  if (b < a)
    cout << -1 << endl;
  else {
    if (a <= pos and b >= pos)
      cout << 0 << endl;
    else
      cout << min(fabs(a - pos), fabs(b - pos)) << endl;
  }

  return 0;
}