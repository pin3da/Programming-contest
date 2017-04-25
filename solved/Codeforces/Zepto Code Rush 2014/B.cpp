// http://codeforces.com/contest/436/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 2020;

char grid[MN][MN];
int ans[MN];


int main() { ___
  int n,m,k;
  memset(ans, 0, sizeof ans);
  cin>>n>>m>>k;

  for (int i = 0 ; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin>>grid[i][j];
      char c = grid[i][j];
      if (c == '.') continue;
      if (c == 'R') {
        if (j + i < m) {
          ans[j + i]++;
        }
      }
      if (c == 'L') {
        if (j - i >= 0) {
          ans[j - i]++;
        }
      }
      if (c == 'U') {
        if((i & 1) == 0) ans[j]++;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    if (i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}

