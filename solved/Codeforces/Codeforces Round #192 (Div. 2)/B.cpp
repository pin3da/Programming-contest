// http://codeforces.com/contest/330/problem/B

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#ifndef BMO
#define endl '\n'
#define _io ios_base::sync_with_stdio(false);cin.tie(NULL);
#else
#define _io
#endif

void solve(int n, int m) {
  vector<bool> seen(n);
  int u, v;
  while (m--) {
    cin >> u >> v;
    seen[u - 1] = seen[v - 1] = true;
  }
  for (int i = 0; i < n; ++i)
    if (!seen[i]) {
      cout << n - 1 << endl;
      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        cout << i + 1 << " " << j + 1 << endl;
      }
      return;
    }

}
int main() { _io
  int n, m;
  while (cin >> n >> m) solve(n, m);
  return 0;
}
