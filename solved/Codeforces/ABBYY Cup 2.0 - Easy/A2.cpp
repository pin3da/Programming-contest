// http://codeforces.com/contest/177/problem/A2

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

void solve(int n) {
  long long ans = 0, t;
  int q = n >> 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> t;
      if (i == q || j == q || (i == j) || (i == (n - 1 - j)))
        ans += t;
    }
  }
  cout << ans << endl;
}

int main() {
  int n;
  while(cin >> n)
    solve(n);
  return 0;
}
