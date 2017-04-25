// http://codeforces.com/contest/29/problem/A

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#ifndef BMO
#define endl '\n'
#define _io ios_base::sync_with_stdio(false);cin.tie(NULL);
#else
#define _io
#endif
struct camel{
  int x, d;
};

void solve(int n) {
  vector<camel> a(n);
  for (auto &i : a) cin >> i.x >> i.d;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (a[i].x == a[j].x + a[j].d && a[j].x == a[i].x + a[i].d) {
        cout << "YES" << endl; return;}
  cout << "NO" << endl;
}

int main() { _io
  int n; while (cin >> n) solve(n);
  return 0;
}
