// http://codeforces.com/contest/500/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


int main() { ___

  int n, t;
  cin >> n >> t;
  vector<int> vis(n, 0), st(n, 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> st[i];
  }

  for (int i = 0; i < n;) {
    vis[i] = true;
    i += st[i];
  }

  t--;
  if (vis[t])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;


  return 0;
}