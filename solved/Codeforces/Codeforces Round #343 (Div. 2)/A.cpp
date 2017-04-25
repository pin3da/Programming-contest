// http://codeforces.com/contest/629/problem/A

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<char>> a(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'C') {
        for (int k = 0; k < n; ++k) {
          if (k > i && a[k][j] == 'C') ans++;
          if (k > j && a[i][k] == 'C') ans++;
        }
      }
    }
  }
  cout << ans << endl;


  return 0;
}