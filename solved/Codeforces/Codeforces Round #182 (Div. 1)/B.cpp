// http://codeforces.com/contest/301/problem/B

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


int main(){

  while(cin>>n>>d){
    for(int i = 1; i < n -1; ++i)
      cin>>recover[i];

    vector<point> p(n);
    for(int i = 0; i< n; ++i)
      cin>>p[i].x>>p[i].y;

    for(int i = 0; i< n; ++i)
      for(int j = 0; j <n; ++j)
        g[i][j] = dist(p[i],p[j])*d - recover[i];


    for(int k = 0;  k < n; ++k)
      for(int i = 0; i < n; ++i)
        for(int j = 0; j< n; ++j){
          if(k==i or j==i or k==j) continue; // Make sure than transition exists
          long long a = (g[i][k] + g[k][j]);
          if(a <= g[i][j]){
            g[i][j] = a;
          }
        }

    cout<<g[0][n-1]<<endl;
  }
  return 0;
}