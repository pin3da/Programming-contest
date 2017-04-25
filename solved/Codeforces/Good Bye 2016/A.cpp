// http://codeforces.com/contest/750/problem/A

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, k;
  cin >> n >> k;
  int total = (4 * 60) - k;
  int ans = 0;
  for (int i = 1; i <= n && total >= (i * 5); ++i) {
    total -= i * 5;
    ans = i;
  }
  cout << ans << endl;
  return 0;
}
