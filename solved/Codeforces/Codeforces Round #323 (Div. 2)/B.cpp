// http://codeforces.com/contest/583/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  vector<int> seen(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    m = max(m, a[i]);
  }

  int val = 0,
      ans = 0;

  while (true) {
    if (ans & 1) {
      for (int i = n - 1; i >= 0; --i) {
        if (!seen[i] && a[i] <= val) {
          val++;
          seen[i] = 1;
        }
      }
    } else {
      for (int i = 0; i < n; ++i) {
        if (!seen[i] && a[i] <= val) {
          val++;
          seen[i] = 1;
        }
      }
    }
    if(accumulate(seen.begin(), seen.end(), 0) == n)
      break;
    ans ++;
  }
  cout << ans << endl;
  return 0;
}