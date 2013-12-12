using namespace std;
#include<bits/stdc++.h>
#define MAXN 111

struct point{
  int x, y;
  point(){}
};

int dist(point &a, point &b){
  return fabs(a.x-b.x) + fabs(a.y -b.y);
}

long long g[MAXN][MAXN];
int next[MAXN][MAXN];
int recover[MAXN];
int n,d;


void path(int i, int j){
  if(next[i][j] == -1)
      cout<<" ";
  else{
    path(i,next[i][j]);
    cout<<next[i][j];
    path(next[i][j],j);
  }
}

int main(){

  while(cin>>n>>d){
    for(int i = 1; i < n -1; ++i)
      cin>>recover[i];

    vector<point> p(n);
    for(int i = 0; i< n; ++i)
      cin>>p[i].x>>p[i].y;

    for(int i = 0; i< n; ++i)
      for(int j = 0; j <n; ++j)
        g[i][j] = dist(p[i],p[j])*d;

    memset(next,-1,sizeof next);

    for(int k = 1;  k < n - 1; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j< n; ++j){
          long long a = (g[i][k] + g[k][j]) - recover[i];
          if(a <= g[i][j]){
            g[i][j] = a;
            next[i][j] = k;
            cout<<"Mejora "<<i<<" "<<k<<" "<<j<<endl;
          }
        }
      }
    }

    //path(0,n-1);

    cout<<g[0][n-1]<<endl;
  }
  return 0;
}
