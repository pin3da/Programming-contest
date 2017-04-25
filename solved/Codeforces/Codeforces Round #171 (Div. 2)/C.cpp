// http://codeforces.com/contest/279/problem/C

#include <bits/stdc++.h>

using namespace std;

const int MN = 123456;
int a[MN];
int inc[MN];
int des[MN];

int main() {
#ifndef LOCAL
  #define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) cin >> a[i];

    inc[n - 1] = des[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
      inc[i] = a[i] <= a[i + 1] ? inc[i + 1] : i;
      des[i] = a[i] >= a[i + 1] ? des[i + 1] : i;
    }

    for (int i = 0; i < m; ++i) {
      int b, e; cin >> b >> e;
      b--;e--;
      puts(des[inc[b]] >= e ? "Yes" : "No");
    }
  }

  return 0;
}
