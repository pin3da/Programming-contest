// http://codeforces.com/contest/499/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() {
  int n, m;
  cin >> n >> m;
  int t = 1;
  int l, r;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    while (t < l) {
      if (l - t >= m)
        t += m;
      else {
        t++;
        ans++;
      }
    }
    while (t <= r) {
      t++;
      ans ++;
    }
  }
  cout << ans << endl;

  return 0;
}