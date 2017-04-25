// http://codeforces.com/contest/374/problem/C

using namespace std;
#include<bits/stdc++.h>

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 1010

char grid[MP][MP];
int n,m;

int id(int i,int j){
  return i*m + j;
}

vector<int> g[MP*MP];
int pi[MP*MP];
int visited[MP*MP];
int color[MP*MP];

void connect(int i, int j, int x, int y){
  int a = id(i,j);
  int b = id(x,y);
  g[a].push_back(b);
  pi[b] = a;
}


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int dfs(int no){
    if(color[no]==1)return true;
    if(color[no]==2)return false;
    color[no]=1;
    for(int i=0;i<g[no].size();++i){
            if(dfs(g[no][i]))return true;
    }
    color[no]=2;
    return false;
}


int cycle(){
  memset(color,0,sizeof color);
  for(int i = 0; i< n*m; ++i){
    if(color[i] == 0){
      if(dfs(i)) return true;
    }
  }
  return false;
}
int me[MP*MP];

int dp(int node){
  if(me[node] != -1) return me[node];
  int ans = 1;
  foreach(k,g[node]){
    ans = max(ans, dp(*k) + 1);
  }
  return me[node] = ans;
}

int maxlen(){
  int ans = 0;
  memset(me, -1, sizeof me);
  for(int i =0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(grid[i][j] == 'D'){
          ans = max(ans,dp(id(i,j)));
      }
    }
  }
  return ans;
}

int main(){ ___

  while(cin>>n>>m){
    for(int i =0 ; i < MP*MP; ++i) g[i].clear();
    memset(pi,-1,sizeof pi);

    for(int i = 0; i< n; ++i)
      for(int j = 0; j< m; ++j)
        cin>>grid[i][j];

    for(int i = 0; i< n; ++i){
      for(int j = 0; j< m; ++j){
        for(int k = 0; k < 4; ++k){
          int x = i + dx[k];
          int y = j + dy[k];
          if(x >= 0 and x < n and y >=0 and y < m){
            if(grid[i][j] == 'D' and grid[x][y] == 'I')
               connect(i,j,x,y);
            if(grid[i][j] == 'I' and grid[x][y] == 'M')
               connect(i,j,x,y);
            if(grid[i][j] == 'M' and grid[x][y] == 'A')
               connect(i,j,x,y);
            if(grid[i][j] == 'A' and grid[x][y] == 'D')
               connect(i,j,x,y);
          }
        }
      }
    }

    if(cycle()) {
        cout<<"Poor Inna!"<<endl;
        continue;
    }

    int ans = (maxlen()/4);
    //D(ans);
    if( ans  == 0) cout<<"Poor Dima!"<<endl;
    else cout<< ans<<endl;
  }

  return 0;
}