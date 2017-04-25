// http://codeforces.com/contest/595/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a, b;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a >> b;
      ans += (a || b);
    }
  }
  cout << ans << endl;
  return 0;
}