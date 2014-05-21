using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

const int MN = 111;
const int oo = 1111;

int n, m;
int color[MN];
int g[MN][MN];
int dist[MN][MN];



int change() {
  for (int i = 1; i < n; ++i) if (color[i] != color[i-1]) return true;
  return false;
}


int getcenter() {
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    dist[i][j] = oo;
    if (g[i][j] == 1)
      dist[i][j] = (color[i] != color[j]);
    if (i == j) dist[i][j] = 0;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int other = dist[i][k] + dist[k][j];
        if (other < dist[i][j]) dist[i][j] = other;
      }
    }
  }

  /*for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout<<dist[i][j];
    }
    cout<<endl;
  }*/


  int mmin = oo;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int mmax = 0;
    for (int j = 0; j < n; ++j)
      mmax = max(mmax, dist[i][j]);
    if (mmax < mmin) {
      mmin = mmax;
      ans = i;
    }
  }
  return ans;

}

void fun(int node, int col) {
  if (color[node] != col) {
    color[node] = col;
    for (int i = 0; i < n; ++i)
      if (g[node][i] != oo) fun (i, col);
  }
}

int main() {

  while (cin>>n>>m and n+m) {
    for (int i = 0; i < n; ++i) {
      cin>>color[i];
      for (int j = 0; j < n; ++j) g[i][j] = oo;
    }
    int u,v;
    for (int i = 0; i < m; ++i) {
      cin>>u>>v;
      u--;v--;
      g[u][v] = 1;
      g[v][u] = 1;
    }

    int ans = 0;
    while (change()) {
      int center =  getcenter();
      fun(center, !color[center]);
      ans++;
    }

    cout<<ans<<endl;
  }
  return 0;
}
