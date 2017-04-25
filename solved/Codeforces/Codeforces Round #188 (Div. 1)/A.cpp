// http://codeforces.com/contest/317/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void solve(long long x, long long y, long long m) {
  if (x >= m || y >= m) {
    cout << 0 << endl;
    return;
  }

  if (x <= 0 && y <= 0) {
    cout << -1 << endl;
    return;
  }


  long long ans = 0;

  if (x < 0 || y < 0) {
    long long d = max(x, y);
    ans += (d - min(x, y) - 1) / d;
  }
  if (x < y) x = x + ans * y;
  else       y = y + ans * x;
  while (x < m && y < m) {
    if (x < y) x = x + y;
    else       y = x + y;
    ans++;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x, y, m;
  while (cin >> x >> y >> m)
    solve(x, y, m);
  return 0;
}
