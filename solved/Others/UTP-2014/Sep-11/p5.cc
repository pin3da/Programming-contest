/**
 * WA on test 3
 * */

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = " << (x) <<endl
#define endl '\n'

const int MN = 1111;
int grid[MN][MN];
int dp[MN][MN];
int pi[MN][MN];
int n;

const int inf = MN * MN;
int go(int x, int y) {
  if (x > n or y > n) return inf;
  if ((x == n - 1) and (y == n - 1))
    return 0;


  if (dp[x][y] != -1) return dp[x][y];
  int best = inf;
  if ( go(x + 1, y) + grid[x][y]  < best) {
    best =  go(x + 1, y) + (grid[x][y]);
    pi[x][y] = 1;
  }
  if ( go(x, y + 1) + grid[x][y] < best ) {
    best = go(x, y + 1) + (grid[x][y]);
    pi[x][y] = 2;
  }

  return dp[x][y] = best;
}

int main() { ___

  cin>>n;
  for (int i = 0; i < n; ++i ) {
    for (int j = 0; j < n; ++j) {
      cin>>grid[i][j];
      int tmp = grid[i][j];
      int two = 0, five = 0;
      while ((tmp % 2) == 0) {
        two++;
        tmp/=2;
      }
      tmp = grid[i][j];
      while ((tmp % 5) == 0) {
        five++;
        tmp/=5;
      }
      grid[i][j] =  min(two, five);
      //cout<<grid[i][j]<<" ";
    }
    //cout << endl;
  }

  memset(dp, -1, sizeof dp);
  memset(pi, -1, sizeof pi);
  int a1 = go(0,0);

  deque<int> ans;


  int x = 0, y = 0;
  while (x !=  (n - 1) or y != (n-1) ) {
    ans.push_back(pi[x][y]);
    if (ans.back() == 1)
      x++;
    else
      y++;
  }

  cout<<a1<<endl;
  for (int i = 0; i < ans.size(); ++i) {
    if (ans[i] == 1)
      cout<<"D";
    else
      cout<<"R";
  }
  cout<<endl;

  return 0;
}
