// http://codeforces.com/contest/454/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


int main() { ___

  int n;cin>>n;

  char g[n][n];
  For(i,n) For (j, n) g[i][j] = '*';
  int j = 0;
  for (int i = n / 2; i > 0; --i, j++) {
    for (int k = 0; k < (j * 2 + 1); ++k) {
      g[j][(n/2) -  j +  k] = 'D';
    }
  }

  For (i, n) {
    g[n/2][i] = 'D';
  }

  j = 0;
  for (int i = n - 1; i > (n / 2); --i, j++) {
    for (int k = 0; k < (j * 2 + 1); ++k) {
      g[n - j - 1][(n/2) - j + k] = 'D';
    }
  }

  For (i, n) {
    For (j,n)
      cout<<g[i][j];
    cout<<endl;
  }

  return 0;
}