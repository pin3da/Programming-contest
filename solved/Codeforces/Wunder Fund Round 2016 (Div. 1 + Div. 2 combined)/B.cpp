// http://codeforces.com/contest/618/problem/B

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int> (n));
  vector<int> v(n, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> ans(n, -1);
  while (accumulate(v.begin(), v.end(), 0) < n - 1) {
    int mmin = n + 10, id;
    for (int i = 0; i < n; ++i) {
      if (v[i]) continue;
      for (int j = 0; j < n; ++j) {
        if (v[j] || (i == j)) continue;
        mmin = min(mmin, a[i][j]);
      }
    }

    for (int i = 0; i < n; ++i) {
      int ok = true;
      if (v[i]) continue;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        ok &= (a[i][j] <= mmin);
      }
      if (ok) {
        ans[i] = mmin;
        v[i] = true;
        break;
      }
    }
  }
  for (auto &i : ans) {
    if (i == -1)
      cout << n << " ";
    else
      cout << i << " ";
  }
  cout << endl;
  return 0;
}

