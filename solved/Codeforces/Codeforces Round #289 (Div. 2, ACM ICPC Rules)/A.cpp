// http://codeforces.com/contest/509/problem/A

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() { ___
  int mat[10][10];
  for (int i = 0; i < 10; ++i) {
    mat[i][0] = 1;
    mat[0][i] = 1;
  }

  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; j++) {
      mat[i][j] = mat[i -1][j] + mat[i][j - 1];
    }
  }

  int n; cin >> n;
  n--;
  cout << mat[n][n] << endl;

  return 0;
}
