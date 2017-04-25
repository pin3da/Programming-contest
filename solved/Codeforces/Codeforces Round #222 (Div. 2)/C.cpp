// http://codeforces.com/contest/378/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 505

template<typename T> void cmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void cmax(T& a, T b) { if (a < b) a = b; }

int n,m,tar;
char grid[MN][MN];
int  forb[MN][MN];
int  visited[MN][MN];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){ ___

  while(cin>>n>>m>>tar){
    for(int i = 0; i< n; ++i)
      for(int j = 0; j < m; ++j)
        cin>>grid[i][j];

    memset(forb, 0, sizeof forb);

    int empty = 0;
    deque<pair<int,int> > p;

    for(int i = 0; i < n ; ++i)
      for(int j = 0; j < m ; ++j)
        if(grid[i][j] == '.'){
          if(p.size() == 0) p.push_back(make_pair(i,j));
          empty++;
        }

    int f = empty - tar;
    while(f){
      int i = p.back().first;
      int j = p.back().second;
      p.pop_back();
      if(forb[i][j]) continue;
      forb[i][j] = true;
      f--;
      if(f==0) break;
      for(int k = 0; k < 4; ++k){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= 0 and x < n and y >= 0 and y < m)
          if(grid[x][y] == '.' and !forb[x][y]) p.push_back(make_pair(x,y));
      }
    }

    for(int i = 0; i < n; ++i ){
      for(int j = 0; j < m; ++j){
        if(grid[i][j] == '.' and !forb[i][j]) grid[i][j] = 'X';
        cout<<grid[i][j];
      }
      cout<<endl;
    }


  }

  return 0;
}0; j < m; ++j){
        if(grid[i][j] == '.' and !forb[i][j]) grid[i][j] = 'X';
        cout<<grid[i][j];
      }
      cout<<endl;
    }


  }

  return 0;
}