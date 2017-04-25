// http://codeforces.com/contest/389/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111

char g[MN][MN];
int visited[MN][MN];

int dx [] = {0,1,2,1,1};
int dy [] = {0,0,0,-1,1};
int n;

bool mark(int i, int j) {
  for (int k = 0; k < 5; ++k ) {
    int x = i + dx[k];
    int y = j + dy[k];
    if (x < 0 or x >= n or y < 0 or y >= n or visited[x][y] or g[x][y] != '#')
        return 0;
    visited[x][y] = true;
  }
  return true;
}

int main() { ___

  cin>>n;
  For (i, n)
    For (j, n)
      cin>>g[i][j];

  memset(visited, 0, sizeof visited);

  For (i, n) {
    For (j, n) {
      if (g[i][j] == '#' and !visited[i][j]) {

        if (!mark(i,j)) {
          cout<<"NO"<<endl;
          return 0;
        }
      }
    }
  }



  cout<<"YES"<<endl;


  return 0;
}