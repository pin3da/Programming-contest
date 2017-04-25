// http://codeforces.com/contest/489/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

int m, s;


int main() { ___


  cin >> m >> s;

  if (s == 0) {
    if (m == 1) {
      cout << 0 << " " << 0 << endl;
      return 0;
    }
    cout << -1 << " " << -1 << endl;
    return 0;
  }

  if (s > 9 * m) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }

  vector<int> mmin(m, 0);
  vector<int> mmax(m, 0);
  int cur = 0;
  for (int i = 0; i < m; ++i ) {
    if (cur < s) {
      int sum = min(s - cur, 9);
      mmax[i] += sum;
      cur += sum;
    }
  }

  mmin[0] = 1;
  cur = 1;
  for (int i = 0; i < m; ++i ) {
    if (cur < s) {
      int sum = min(s - cur, 9);
      mmin[m - 1 - i] += sum;
      cur += sum;
    }
  }

  for (int i = 0; i < m; ++i )
    cout << mmin[i];
  cout << " ";

  for (int i = 0; i < m; ++i )
    cout << mmax[i];
  cout << endl;

  return 0;
}